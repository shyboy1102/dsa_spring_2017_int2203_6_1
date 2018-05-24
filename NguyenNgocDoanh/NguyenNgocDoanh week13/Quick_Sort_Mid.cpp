#include<iostream>
#include<fstream>
#define MAX_ARRAY 10000
using namespace std;

void swap(int * x, int * y){
	int * t = x;
	x = y;
	y = t;
}

void Quick_Sort_Mid(int A[], int l, int r){
	int i = l, j = r;
	int m = (l+r)/2; // mid

	/* Partition */
	while(i<=j){
		while(A[i] < A[m])
			i++;
		while(A[j] > A[m])
			j--;
		if(i<=j){
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}

	/* Recursion */
	if(l<j)
		Quick_Sort_Mid(A,l,j);
	if(i<r)
		Quick_Sort_Mid(A,i,r);
}


int main(){
	int A[MAX_ARRAY];
	int n=0;

	ifstream i_file("input.txt");
	while(!i_file.eof()){
		i_file >> A[n++];
	}

	Quick_Sort_Mid(A, 0, n-1);

	ofstream o_file("output.txt");
	for(int i=0;i<n;i++)
		o_file << A[i] << endl;

	o_file.close();
	i_file.close();
	return 0;
}