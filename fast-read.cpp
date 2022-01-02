#include <cstdio>

inline int/* the 'int' can  replace to __int128 etc.*/ read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}

// int128 writing
inline void write(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}
