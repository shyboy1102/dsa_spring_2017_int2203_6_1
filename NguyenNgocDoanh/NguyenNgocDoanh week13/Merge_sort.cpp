#include<iostream>
#include<fstream>
using namespace std;

#define MAX_ARRAY 1000

int max(int A[], int n){
	int max=A[0];
	for(int i=1;i<n;i++)
		A[i] > max ? A[i] : max;
	return max;
}

void Merge(int A[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int Left[n1];
	int Right[n2];
	for(int i=0;i<n1;i++)
		Left[i] = A[l+i];
	for(int j=0;j<n2;j++)
		Right[j] = A[m+j+1];
	Left[n1] = 10000;
	Right[n2] = 10000;
	int i=0;
	int j=0;
	for(int k=l;k<=r;k++){
		if(Left[i] <= Right[j]){
			A[k] = Left[i];
			i++;
		}
		else {
			A[k] = Right[j];
			j++;
		}
	}
}

void Merge_Sort(int A[], int l, int r){
	if(l < r){
		int m = (l+r)/2;
		Merge_Sort(A,l,m);
		Merge_Sort(A,m+1,r);
		Merge(A,l,m,r);
	}
}

int main(){
	int A[MAX_ARRAY];
	int n=0;
	ifstream ifile ("input.txt");
	if(ifile.is_open()){
		while(!ifile.eof()){
			ifile >> A[n++];
		}
	}

	Merge_Sort(A,0,n-1);

	ofstream ofile ("output.txt");
	for(int i=0;i<n;i++)
		ofile << A[i] << endl;

	ifile.close();
	ofile.close();
	return 0;
}

