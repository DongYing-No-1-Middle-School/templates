#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 1000001

/* Block Range */
int arr[MAXN], block_size, block_num, arr_length, sum[MAXN], mark[MAXN],
    _size[MAXN], belong[MAXN];
int L[MAXN], R[MAXN];

void build() {
  block_size = sqrt(arr_length);
  block_num = arr_length / block_size;
  if (arr_length % block_num) block_num++;
  for (register int i = 1; i <= block_num; i++)
    R[i] = i * block_size, L[i] = R[i - 1] + 1;
  R[block_num] = arr_length;
  for (register int i = 1; i <= arr_length; i++)
    belong[i] = (i - 1) / block_size + 1;
  for (register int i = 1; i <= block_num; i++) {
    for (register int j = L[i]; j <= R[i]; j++) sum[i] += arr[j];
    _size[i] = R[i] - L[i] + 1;
  }
}
int main() {
  cout << "Succeed." << '\n';
  return 0;
}