#include <algorithm>
#include <iostream>

using namespace std;

void knapsack(int n, double w[], double p[], double m) {
  double arr[n] = {0}, tp = 0;
  int i;
  for (i = 0; i < n; i++) {
    if (w[i] > m) {
      break;
    } else {
      arr[i] = 1, tp += p[i], m -= w[i];
    }
  }
  if (i < n) {
    arr[i] = m / w[i];
    tp += (arr[i] * p[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << tp << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  double w[n], p[n], pw[n];
  for (int i = 0; i < n; i++) cin >> w[i] >> p[i];
  for (int i = 0; i < n; i++) pw[i] = p[i] / w[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (pw[i] < pw[j]) {
        swap(pw[i], pw[j]);
        swap(w[i], w[j]);
        swap(p[i], p[j]);
      }
    }
  }
  knapsack(n, w, p, m);
  return 0;
}