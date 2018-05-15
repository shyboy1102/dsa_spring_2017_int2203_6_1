#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

void QuickSortMid(int A[], int a, int b);

void QuickSortMid(int A[], int a, int b)
{
	if(a<=b)
	{
		int pivot = A[(a+b)/2];
		int left = a;
		int right = b;
		while(left<=right)
		{
			while(A[left]<pivot)
				left++;
			while(A[right]>pivot)
				right--;
			if(left<=right)
			{
				swap(A[left], A[right]);
				left++;
				right--;
			}
		}
		if(a<right)
			QuickSortMid(A,a,right);
		if(b>left)
			QuickSortMid(A,left,b);
	}
}

int main(){
	int A[100];
	int a,b,n;
	string line;
	ifstream ifs("input1.txt");
	while(!ifs.eof()){
		
		ifs>>A[n];
		if(ifs.eof()){
			break;
		}
		cout<<A[n]<<endl;
		n++;
	}
	cout<<"So phan tu trong file:"<<n<<endl;
	ifs.close();
	QuickSortMid(A,0,n-1);
	ofstream ofs("output3.txt");
	for(int i=0;i<n;i++){
		ofs<<A[i]<<endl;
		cout<<A[i]<<endl;
	}
	ofs.close();
	return 0;
}
