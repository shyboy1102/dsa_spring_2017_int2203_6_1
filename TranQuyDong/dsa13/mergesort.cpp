#include<iostream>
#include<fstream>
#include <string.h>
#include<string>
using namespace std;

void MergeSort(int A[], int a, int b);
void Merge(int A[], int a, int c, int b);

void MergeSort(int A[], int a, int b)
{
	if(a<b)
	{
		int c = (a+b)/2;
		MergeSort(A,a,c);
		MergeSort(A,c+1,b);
		Merge(A,a,c,b);
	}
}

void Merge(int A[], int a, int c, int b)
{
	int i = a;
	int j = c+1;
	int k = 0;
	int n = b-a+1;
	int* B = new int[n];
	while(i<c+1 && j<b+1){
		if(A[i]<A[j])
			B[k++] = A[i++];
		else 
			B[k++] = A[j++];
	}
	while(i<c+1)
		B[k++] = A[i++];
	while(j<b+1)
		B[k++] = A[j++];
	i = a;
	for(k=0;k<n;k++)
		A[i++] = B[k];
	delete B;
}

int main()
{
	int A[100];
	int a,b,n;
	string line;
	ifstream ifs("input1.txt");
	while(!ifs.eof())
	{
		ifs>>A[n];
		if(ifs.eof()){
			break;
		}
		cout<<A[n]<<endl;
		n++;
	}
	cout<<"So phan tu trong file:"<<n<<endl;
	ifs.close();
	MergeSort(A,0,n-1);
	ofstream ofs("output1.txt");
	for(int i=0;i<n;i++)
	{
		ofs<<A[i]<<endl;
		cout<<A[i]<<endl;
	}
	ofs.close();
	return 0;
}

