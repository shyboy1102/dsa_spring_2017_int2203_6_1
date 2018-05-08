#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output1.txt");
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
    mergeSort(B, 0, n-1);

    cout << "Writing..." << endl;
    for(i = 0; i < n; i++) {
        outfile << B[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}
