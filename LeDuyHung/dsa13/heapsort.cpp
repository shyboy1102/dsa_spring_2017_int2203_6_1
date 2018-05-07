#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output4.txt");
    int n, i, a;
    vector<int> A;

    cout << "Reading..." << endl;
    while(infile >> a) {
		A.push_back(a);
    }
    n = A.size();
    int B[n];
    for(i = 0; i < n; i++) {
        B[i] = A[i];
    }

    cout << "Sorting..." << endl;
    heapSort(B, n);

    cout << "Writing..." << endl;
    for(i = 0; i < n; i++) {
        outfile << B[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}

