#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

// dinh nghia ham swap
void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// xay dugn ham quickSort vs chot o giua
void quickSort(int A[], int a, int b){
	int x=(a+b)/2;
	int left = a;
	int right = b;
	do {
		while (A[left] < A[x]) left++;
		while (A[right] > A[x]) right--;
		if (left <= right ){
			swap(A[left], A[right]);
			left ++;
			right --;
		}
	}while (left < right);

	if (a < right) quickSort(A,a,right);

	if (left < b) quickSort(A, left, b);
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output3.txt");
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

    quickSort(B, 0, n-1);

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
