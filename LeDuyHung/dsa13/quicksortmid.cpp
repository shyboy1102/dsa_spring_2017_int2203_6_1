#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSortMid(int arr[], int left, int right) {
    if(left >= right) {
        return;
    }
    int lefttemp = left;
    int righttemp = right;
    int pivot = arr[(right + left) / 2];
    while(lefttemp <= righttemp) {
        while(arr[lefttemp] < pivot ) {
            lefttemp++;
        }
        while(arr[righttemp] > pivot ) {
            righttemp--;
        }
        if(lefttemp <= righttemp) {
            swap(arr[lefttemp], arr[righttemp]);
            lefttemp++;
            righttemp--;
        }
    }
    if(left < righttemp) {
        quickSortMid(arr, left, righttemp);
    }
    if(lefttemp < right) {
        quickSortMid(arr, lefttemp, right);
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output3.txt");
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
    quickSortMid(B, 0, n-1);

    cout << "Writing..." << endl;
    for(i = 0; i < n; i++) {
        outfile << B[i] << endl;
    }
    infile.close();
    outfile.close();
    cout << "Done!" << endl;
    return 0;
}

