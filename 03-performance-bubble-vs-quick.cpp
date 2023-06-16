// Dabananda Mitra, CSE (2019-20), ISTT.
// Email: imdmitra@outlook.com

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int partition(int arr[], int low, int high) {
  int index = low - 1, pivot = arr[high];
  for (int i = low; i < high; i++) {
    if (arr[i] < pivot) {
      swap(arr[++index], arr[i]);
    }
  }
  swap(arr[++index], arr[high]);
  return index;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high) return;
  int p = partition(arr, low, high);
  quickSort(arr, low, p - 1);
  quickSort(arr, p + 1, high);
}

int main() {
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10000;  // rand() % n will produce numbers between 0 to n - 1
  }
  time_t start, end;
  start = clock();
  bubbleSort(arr, size);
  end = clock();
  cout << "Time taken by Bubble sort: " << difftime(end, start) << endl;
  start = clock();
  quickSort(arr, 0, size - 1);
  end = clock();
  cout << "Time taken by Quick sort: " << difftime(end, start) << endl;
  return 0;
}