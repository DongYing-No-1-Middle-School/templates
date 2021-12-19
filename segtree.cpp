#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
#define MAXN 1000010

struct node {
  int l, r, sum, len, tag;
  node operator+(node& x) const {
    return {l, x.r, sum + x.sum, len + x.len, 0};
  }
} stree[MAXN << 2];

int arr[MAXN];
#define pushup(now) stree[now] = stree[now << 1] + stree[now << 1 | 1]

void build(int now, int l, int r) {
  if (l == r) {
    stree[now] = {l, r, arr[l], 1, 0};
    return;
  }
  int mid = (l + r) >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);

  pushup(now);
}
void givetag(int now, int tag) {
  if (stree[now].l == stree[now].r) {
    stree[now].sum += tag;
    return;
  }
  stree[now].sum += stree[now].len * tag;
  stree[now].tag += tag;
}
void pushdown(int now) {
  int tag = stree[now].tag;
  givetag(now << 1, tag);
  givetag(now << 1 | 1, tag);
  stree[now].tag = 0;
}
int query(int now, int l, int r) {
  if (stree[now].tag)
    pushdown(now);
  if (stree[now].l >= l && stree[now].r <= r)
    return stree[now].sum;
  if (stree[now].r < l || stree[now].l > r)
    return 0;
  return query(now << 1, l, r) + query(now << 1 | 1, l, r);
}
void change(int now, int l, int r, int k) {
  if (stree[now].tag)
    pushdown(now);
  if (stree[now].l >= l && stree[now].r <= r) {
    givetag(now, k);
    return;
  } else if (stree[now].r < l || stree[now].l > r)
    return;
  else {
    change(now << 1, l, r, k);
    change(now << 1 | 1, l, r, k);
  }
  pushup(now);
}

signed main() {
  int n, m;
  cin >> n >> m;
  for (register int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  build(1, 1, n);
  while (m--) {
    int opt;
    cin >> opt;
    switch (opt) {
      case 1:
        int a, b, c;
        cin >> a >> b >> c;
        change(1, a, b, c);
        break;
      case 2:
        int d, e;
        cin >> d >> e;
        cout << query(1, d, e) << endl;
        break;
    }
  }
}
