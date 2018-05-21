#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = (right + 1);
    for(int j = right; j >= left + 1; j--) {
        if(arr[j] >= pivot) {
            i--;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i - 1], &arr[left]);
    return (i - 1);
}

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int par = partition(arr, left, right);
        quickSort(arr, left, par - 1);
        quickSort(arr, par + 1, right);
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output2.txt");
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
    quickSort(B, 0, n-1);

    cout << "Writing..." << endl;
    for(i = 0; i < n; i++) {
        outfile << B[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}
