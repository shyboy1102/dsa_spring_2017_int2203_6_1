#include<iostream>

using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void radixsort(int arr[], int n) {
    int output[n];
    int exp = 1;
    int mx = getMax(arr, n);
    while(mx / exp > 0) {
        int C[10] = {0};
        for(int i = 0; i < n; i++) {
            C[arr[i] / exp % 10]++;
        }
        for(int i = 1; i < 10; i++) {
            C[i] += C[i-1];
        }
        for(int i = n-1; i >= 0; i--) {
            output[--C[arr[i] / exp % 10]] = arr[i];
        }
        for(int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        exp *= 10;
    }
}

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {170, 128, 45, 75, 90, 802, 18, 24, 2, 59, 66, 303};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    print(arr, n);

    radixsort(arr, n);

    cout << "After sorting: ";
    print(arr, n);
    return 0;
}
