#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 10000010

struct node {
  int l, r, sum, len, tag;
  node operator+(node& x) const {
    return {l, x.r, sum + x.sum, len + x.len, 0};
  }
} stree[MAXN << 2];

int main() {}