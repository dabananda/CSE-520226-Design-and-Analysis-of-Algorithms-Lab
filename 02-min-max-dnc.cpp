// Dabananda Mitra, CSE (2019-20), ISTT.
// Email: imdmitra@outlook.com

#include <iostream>
using namespace std;

int minMax(int arr[], int low, int high, int &min, int &max) {
  int mid, min1, max1;
  if (low == high) {
    min = max = arr[low];
  } else if (high == low + 1) {
    if (arr[low] < arr[high]) {
      min = arr[low], max = arr[high];
    } else {
      min = arr[high], max = arr[low];
    }
  } else {
    mid = (low + high) / 2;
    minMax(arr, low, mid - 1, min, max);
    minMax(arr, mid + 1, high, min1, max1);
    if (max < max1) {
      max = max1;
    }
    if (min > min1) {
      min = min1;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int min, max;
  minMax(arr, 0, n - 1, min, max);
  cout << "Min: " << min << "\nMax: " << max << endl;

  return 0;
}