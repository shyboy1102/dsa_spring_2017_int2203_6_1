#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

// Dinh nghia ham merge
void merge(int A[], int l, int m, int r) {
    int i, j, k;
    int length1 = m - l + 1;
    int length2 = r - m;

    int L[length1];
	int R[length2];
// chia mang A thanh 2 mang roi copy vao mang L va R
    for(i = 0; i < length1; i++) {
        L[i] = A[l + i];
    }
    for(j = 0; j < length2; j++) {
        R[j] = A[m + 1+ j];
    }
//sap xep va chep lai vao mang A
    i = 0;
    j = 0;
    k = l;

    while(i < length1 && j < length2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < length1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while(j < length2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

//ding nghia ham mergeSort
void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        cout <<m<< endl;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output1.txt");
// copy data tu file vao mang B
    int n, i, a;
    vector<int> A;

    while(infile >> a) {
		A.push_back(a);
    }
    n = A.size();
    int B[n];
    for(i = 0; i < n; i++) {
        B[i] = A[i];
    }
    
    cout << "Read done." << endl;

    mergeSort(B, 0, n-1);
    
    cout << "Sort done." << endl;
    
// copy vao file output1.txt
    for(i = 0; i < n; i++) {
        outfile << B[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done." << endl;
    return 0;
}
