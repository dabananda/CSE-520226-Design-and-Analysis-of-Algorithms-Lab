#include <climits>
#include <iostream>
#define n 6

using namespace std;

int minDist(int dist[], bool spt[]) {
  int min = INT_MAX, minIndex;
  for (int i = 0; i < n; i++) {
    if (spt[i] == false && dist[i] <= min) {
      min = dist[i], minIndex = i;
    }
  }
  return minIndex;
}

void dijkstra(int graph[n][n]) {
  int dist[n];
  bool spt[n];
  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX, spt[i] = false;
  }
  dist[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    int u = minDist(dist, spt);
    spt[u] = true;
    for (int v = 0; v < n; v++) {
      if (!spt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  cout << "Vertex\t\tDistance" << endl;
  for (int i = 0; i < n; i++) {
    cout << i << "\t\t" << dist[i] << endl;
  }
}

int main() {
  int graph[n][n] = {
      {0, 50, 45, 10, 99, 99},
      {99, 0, 10, 15, 99, 99},
      {99, 99, 0, 99, 30, 99},
      {20, 99, 99, 0, 15, 99},
      {99, 20, 35, 99, 0, 99},
      {99, 99, 99, 99, 3, 99}};
  dijkstra(graph);
  return 0;
}