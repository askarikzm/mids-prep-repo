#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int an = mid - left + 1;
    int bn = right - mid;
    int a[an], b[bn]; // temp arrays

    for (int i = 0; i < an; i++) {
        a[i] = arr[left + i];
    }
    for (int i = 0; i < bn; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < an && j < bn) {
        if (a[i] < b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
  // put the remaning Sorting element as left in array are lesser
    while (i < an) {
        arr[k++] = a[i++];
    }

    while (j < bn) {
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return; // base csse
    }
    int mid =  round((left+right) / 2);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
}

int main() {
    int arr[10] = {34, 4, 33, 40, 1, 3, 2, 5, 62, 41};
    mergeSort(arr, 0, 10-1);
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i]<<endl;
    }
    cout << endl;

    return 0;
}
