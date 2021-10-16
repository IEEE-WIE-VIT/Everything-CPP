/*
n = t.length
m = p.length
h = dm-1 mod q
p = 0
t0 = 0
for i = 1 to m
    p = (dp + p[i]) mod q
    t0 = (dt0 + t[i]) mod q
for s = 0 to n - m
    if p = ts
        if p[1.....m] = t[s + 1..... s + m]
            print "pattern found at position" s
    If s < n-m
        ts + 1 = (d (ts - t[s + 1]h) + t[s + m + 1]) mod q */
#include <string.h>
#include <iostream>
#define d 10
using namespace std;

void rabin(char pattern[], char string[], int q) {
  int m = strlen(pattern);
  int n = strlen(string);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;
  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + string[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (string[i + j] != pattern[j])
          break;
      }
      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }
    if (i < n - m) {
      t = (d * (t - string[i] * h) + string[i + m]) % q;
      if (t < 0)
        t = (t + q);
    }
  }
}
int main() {
  char string[] = "Hello World!This is Rabin Karp Algorithm.";
  char pattern[] = "Rabin Karp";
  int q = 13;
  rabin(pattern, string, q);
}
