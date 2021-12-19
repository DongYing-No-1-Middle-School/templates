#include<bits/stdc++.h>
long long a[100005],sum[100005],mark[100005],value;
int block,num,belong[100005],l[100005],r[100005],_size[100005],n,m,opt,from,to;
inline void write(long long x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
}
inline void f_read(long long &x){
	int w=1;x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x*=w;
}
inline void build(){
    block=sqrt(n);
    num=n/block;if(n%block)++num;
    for(int i=1;i<=num;++i)l[i]=(i-1)*block+1,r[i]=i*block;
    r[num]=n;
    for(int i=1;i<=n;++i)belong[i]=(i-1)/block+1;
    for(int i=1;i<=num;++i){
        for(int j=l[i];j<=r[i];++j)sum[i]+=a[j];
        _size[i]=r[i]-l[i]+1;
    }
}
inline long long query(int x,int y){
    long long ans(0);
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;++i)ans+=(a[i]+mark[belong[x]]);
        return ans;
    }
    for(int i=x;i<=r[belong[x]];++i)ans+=(a[i]+mark[belong[x]]);
    for(int i=belong[x]+1;i<belong[y];++i)ans+=(sum[i]+mark[i]*_size[i]);
    for(int i=l[belong[y]];i<=y;++i)ans+=(a[i]+mark[belong[y]]);
    return ans;
}
inline void change(int x,int y,long long v){
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;++i)a[i]+=v;
        sum[belong[x]]+=_size[belong[x]]*v;
        return;
    }
    sum[belong[x]]+=(r[belong[x]]-x+1)*v;
    sum[belong[y]]+=(y-l[belong[y]]+1)*v;
    for(int i=x;i<=r[belong[x]];++i)a[i]+=v;
    for(int i=belong[x]+1;i<belong[y];++i)mark[i]+=v;
    for(int i=l[belong[y]];i<=y;++i)a[i]+=v;
}
int main(){
    read(n),read(m);
    for(int i=1;i<=n;++i)f_read(a[i]);
    build();
    while(m--){
        read(opt);
        if(opt==1){
            read(from),read(to),f_read(value);
            change(from,to,value);
        }else{
            read(from),read(to);
            write(query(from,to));
            putchar('\n');
        }
    }
    return 0;
}