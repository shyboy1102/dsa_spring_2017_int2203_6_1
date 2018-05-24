#include<iostream >
#include<time.h>
#include<fstream>
#include<cstdlib>
#include <algorithm> 
using namespace std;

void LinearSort(int A[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(A[i]>A[j])
				swap(A[i],A[j]);
}
int main()
{
	int n,A[100];
	srand(time(NULL));
	cout<<"So phan tu n:";
	cin>>n;
	cout<<"Cac phan tu trong mang A[]:"<<endl;
	for(int i=0;i<n*n-1;i++)
	{
		A[i] = rand()%30+1;
		cout<<A[i]<<endl;
	}
	random_shuffle(A,A+n);
	cout<<"n phan tu trong A[]:"<<endl;
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
	LinearSort(A,n);
	cout<<"n phan tu sau khi sap xep:"<<endl;
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
}
