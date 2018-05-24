#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

void HeapSort(int A[], int n);
void ShiftDown(int A[], int a, int b);

void HeapSort(int A[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		ShiftDown(A,i,n-1);
	for(int i=n-1;i>=1;i--)
	{
		swap(A[0],A[i]);
		ShiftDown(A,0,i-1);
	}
}

void ShiftDown(int A[],int a, int b)
{
	int i = a;
	int j = 2*i+1;
	while(j<=b)
	{
		int k = j+1;
		if(k<=b&&A[k]<A[j])
			j = k;
		if(A[i]>A[j]){
			swap(A[i],A[j]);
			i = j;
			j = 2*i+1;
		}
		else break;
	}
}

int main(){
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
	HeapSort(A,n);
	ofstream ofs("output3.txt");
	for(int i=n-1;i>=0;i--)
	{
		ofs<<A[i]<<endl;
		cout<<A[i]<<endl;
	}
	ofs.close();
	return 0;
}
