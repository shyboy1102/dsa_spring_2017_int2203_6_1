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

// xay dung ham partition
int partition(int A[], int a, int b, int &k) {
// gan moc bang phan tu dau tien
    int pivot = A[a];
    int left = a+1;
    int right = b;
// left tang cho den khi A[left] > pivot
//right giam cho den khi A[right < pivot
// swap A[left] va A[right]
    do {
    	while ((left<=right) && A[left] <= pivot)
    		left ++;
    	while ((left <= right) && A[right] > pivot)
    		right --;
    	if (left < right) {
    		swap (A[left], A[right]);
    		left ++;
    		right --;
		}
	}while (left <= right);
	swap (A[a], A[right]);
	k = right;
}

void quickSort(int A[], int a, int b) {
    if(a < b) {
    	int k;
		partition(A, a, b, k);
		if (a <= k-1)
			quickSort(A, a, k-1);
		if (k+1 <=b)
			quickSort (A, k+1, b);
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
