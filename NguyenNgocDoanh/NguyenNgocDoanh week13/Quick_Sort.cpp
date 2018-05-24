#include<iostream>
#include<fstream>
#define MAX_ARRAY 10000

using namespace std;

void swap(int * x, int * y){
	int * t = x;
	x = y;
	y = t;

}

int Partition(int A[], int p, int r){
	int x = A[p];
	int i = p;
	for(int j=p+1;j<=r;j++){
		if(A[j] <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i], A[p]);
	return i;
}

void Quick_Sort(int A[], int p, int r){
	if(p<r){
		int q = Partition(A,p,r);
		Quick_Sort(A,p,q-1);
		Quick_Sort(A,q+1,r);
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

	Quick_Sort(A,0,n-1);
	ofstream ofile ("output.txt");
	for(int i=0;i<n;i++)
		ofile << A[i] << endl;

	ifile.close();
	ofile.close();
	return 0;
}