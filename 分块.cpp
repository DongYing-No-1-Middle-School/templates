#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100005
#define ll long long
ll a[MAXN], sum[MAXN], mark[MAXN];
int block, num, belong[MAXN], l[MAXN], r[MAXN], _size[MAXN], n, m;
inline void build() {
  block = sqrt(n);
  num = n / block;
  if (n % block)
    ++num;
  for (register int i = 1; i <= num; ++i)
    l[i] = (i - 1) * block + 1, r[i] = i * block;
  r[num] = n;
  for (register int i = 1; i <= n; ++i)
    belong[i] = (i - 1) / block + 1;
  for (register int i = 1; i <= num; ++i) {
    for (register int j = l[i]; j <= r[i]; ++j)
      sum[i] += a[j];
    _size[i] = r[i] - l[i] + 1;
  }
}
inline ll query(int x, int y) {
  ll ans(0);
  if (belong[x] == belong[y]) {
    for (register int i = x; i <= y; ++i)
      ans += a[i] + mark[belong[x]];
    return ans;
  }
  for (register int i = x; i <= r[belong[x]]; ++i)
    ans += (a[i] + mark[belong[x]]);
  for (register int i = belong[x] + 1; i < belong[y]; ++i)
    ans += (sum[i] + mark[i] * _size[i]);
  for (register int i = l[belong[y]]; i <= y; ++i)
    ans += (a[i] + mark[belong[y]]);
  return ans;
}
inline void change(int x, int y, ll v) {
  if (belong[x] == belong[y]) {
    for (register int i = x; i <= y; ++i) {
      a[i] += v;
      sum[belong[x]] += v;
    }
    return;
  }
  for (register int i = x; i <= r[belong[x]]; ++i) {
    a[i] += v;
    sum[belong[x]] += v;
  }
  for (register int i = belong[x] + 1; i < belong[y]; ++i)
    mark[i] += v;
  for (register int i = l[belong[y]]; i <= y; ++i) {
    a[i] += v;
    sum[belong[y]] += v;
  }
}
int main() {
  cin >> n >> m;
  for (register int i = 1; i <= n; ++i)
    cin >> a[i];
  build();
  int opt, from, to;
  ll value;
  for (register int i = 1; i <= m; ++i) {
    cin >> opt;
    if (opt == 1) {
      cin >> from >> to >> value;
      change(from, to, value);
    } else {
      cin >> from >> to;
      printf("%lld\n", query(from, to));
    }
  }
  return 0;
}
