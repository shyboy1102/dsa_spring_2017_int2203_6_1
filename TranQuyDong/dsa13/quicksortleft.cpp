#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

void QuickSortLeft(int A[], int a, int b);
void Partition(int A[], int a, int b, int &k);

void QuickSortLeft(int A[], int a, int b)
{
	if(a<=b)
	{
		int k;
		Partition(A,a,b,k);
		if(a<=k-1)
			QuickSortLeft(A,a,k-1);
		if(k+1<=b)
			QuickSortLeft(A,k+1,b);
	}
}

void Partition(int A[], int a, int b, int &k)
{
	int pivot = A[a];
	int left = a+1;
	int right = b;
	do{
		while(left<=right && A[left]<=pivot)
			left++;
		while(left<=right && pivot<=A[right])
			right--;
		if(left<right)
		{
			swap(A[left], A[right]);
			left++;
			right--;
		}
	}
	while(left<=right);
	swap(A[a], A[right]);
	k = right;
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
	QuickSortLeft(A,0,n-1);
	ofstream ofs("output2.txt");
	for(int i=0;i<n;i++)
	{
		ofs<<A[i]<<endl;
		cout<<A[i]<<endl;
	}
	ofs.close();
	return 0;
}
