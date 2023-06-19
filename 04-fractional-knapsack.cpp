// Dabananda Mitra, CSE (2019-20), ISTT.
// Email: imdmitra@outlook.com

#include <iostream>

using namespace std;

float knapsack(int n, float p[], float w[], int m) {
  int i;
  float pw[n], tp = 0;
  for (int i = 0; i < n; i++) {
    pw[i] = p[i] / w[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (pw[i] < pw[j]) {
        swap(pw[i], pw[j]);
        swap(p[i], p[j]);
        swap(w[i], w[j]);
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (w[i] > m) {
      break;
    } else {
      tp += p[i];
      m -= w[i];
    }
  }
  if (i < n) {
    tp += (m / w[i]) * p[i];
  }
  return tp;
}

int main() {
  int n, m;
  cin >> n >> m;
  float p[n], w[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> w[i];
  }
  cout << knapsack(n, p, w, m) << endl;

  return 0;
}