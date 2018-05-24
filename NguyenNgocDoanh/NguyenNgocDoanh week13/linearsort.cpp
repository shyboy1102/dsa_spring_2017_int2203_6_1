#include<iostream>
#include<stdlib.h>
#define MAX_ARRAY 1000
using namespace std;

void Counting_sort(int A[], int n, int B[], int k){
	int C[k];
	for(int i=0;i<=k;i++)
		C[i] = 0;
	for(int j=0;j<n;j++)
		C[A[j]]++;
	for(int i=1;i<=k;i++)
		C[i] += C[i-1];
	for(int j = n;j>0;j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}



int main(){
	int A[MAX_ARRAY], B[MAX_ARRAY], n;
	//cout << "Nhap n = ";
	//cin >> n;
	
	n = 6;
	int k = n*n-1;
	for(int i=1;i<=n;i++)
		A[i] = rand() % k;

	Counting_sort(A, n, B, k);

	for(int i=1;i<=n;i++)
		cout << B[i] << endl;
	return 0;
}