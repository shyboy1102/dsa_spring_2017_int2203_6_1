#include <iostream>
#include <fstream>
#define MAX 1000
using namespace std;

int max(int a[], int n){
    int amax = a[0];
        for(int i=0; i < n; i++){
            if(a[i] > amax)
                amax = a[i];
        }
    return amax;
}
void RadixSort(int a[], int n)
{
		int b[MAX], exp = 1;
		int amax = max(a,n);
		while (amax/exp > 0)
		{
			int C[10] = {0};
			for (int i = 0; i < n; i++)
				C[a[i] / exp % 10]++;
			for (int i = 1; i < 10; i++)
				C[i] += C[i-1];
			for (int i = n-1; i >= 0; i--)
				b[--C[a[i] / exp % 10]] = a[i];
			for (int i = 0; i < n; i++)
				a[i] = b[i];
			exp *= 10;
		}
}
int main(){
    int a[] = {4,21,675,3,44,956,100,2331};
    int n = sizeof(a)/sizeof(a[0]);
    RadixSort(a,n);
    for(int i=0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
