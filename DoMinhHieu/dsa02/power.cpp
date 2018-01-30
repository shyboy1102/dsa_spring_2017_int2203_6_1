#include<iostream>
using namespace std;
int exp1(int x,int n)
{
	if(n==1)
	{
		return x;
	}
	if((n%2)*2==n)
	{
		return exp1(x*x,n/2);
	}
	else
	{
		return x*exp1(x,n-1);
	}
}
//Time: 12log2(n)+1

int main()
{
	cout<<exp1(3,2);
	return 0;
}
