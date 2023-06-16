// Dabananda Mitra, CSE (2019-20), ISTT.
// Email: imdmitra@outlook.com

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
  if (high >= low) {
    int mid = (low + high) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] > x) {
      return binarySearch(arr, low, mid - 1, x);
    } else {
      return binarySearch(arr, mid + 1, high, x);
    }
  } else {
    return -1;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int x;
  cin >> x;
  int index = binarySearch(arr, 0, n - 1, x);
  if (index != -1) {
    cout << "Element found at index: " << index << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}