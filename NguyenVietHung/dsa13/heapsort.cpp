#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

void swap ( int *a, int *b) {
	int k=*a;
	*a = *b;
	*b = k;
}

//hoan vi nut cha voi nut con
void heapify (int A[], int n, int i){
	int left = 2*(i+1)-1;
	int right = 2*(i+1);
	int largest;
	if (left < n && A[left] > A[i])
		largest = left;
	else
		largest = i;
	if(right < n && A[right] > A[largest])
		largest = right;
	if (i != largest){
		swap (A[i], A[largest]);
		heapify(A, n, largest);
	}
}

// ham heap xay dung sao cho moi nut cha deu lon hon nut con tren cay
void buildHeap (int A[], int n){
	for (int i =n/2 - 1; i >= 0; i--)
		heapify(A, n, i);
}

void heapsort (int A[], int n){
	buildHeap (A, n);
	for (int i = n-1; i>0; i--){
		swap(A[0], A[i]);
		heapify (A, i, 0);
	}
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output4.txt");
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

    heapsort(B, n);

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
