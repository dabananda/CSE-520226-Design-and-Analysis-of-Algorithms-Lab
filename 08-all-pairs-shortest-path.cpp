#include <algorithm>
#include <iostream>
#define MAX 50

using namespace std;

void allPath(int G[MAX][MAX], int n) {
  int A[n][n], i, j, k, x, y;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      A[i][j] = G[i][j];
    }
  }
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
      }
    }
  }
  cout << "Enter the source node: ";
  cin >> x;
  cout << "Enter the destination node: ";
  cin >> y;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Shortest path between source and destination is: " << A[x - 1][y - 1] << endl;
}

int main() {
  int G[MAX][MAX], i, j, n;
  cout << "Enter number of vertex: ";
  cin >> n;
  cout << "Enter the adjacency matrix:" << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> G[i][j];
    }
  }
  allPath(G, n);

  return 0;
}