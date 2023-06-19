// Dabananda Mitra, CSE (2019-20), ISTT.
// Email: imdmitra@outlook.com

#include <iostream>
#include <algorithm>
#define v 10

using namespace std;

int g[v][v];

void floydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  floydWarshall(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}