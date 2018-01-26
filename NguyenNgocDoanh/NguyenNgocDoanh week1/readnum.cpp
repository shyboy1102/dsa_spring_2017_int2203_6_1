#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

#define MAX_ARRAY 1000

int main(){
	int i,inc = 0,n,k;
	int a[MAX_ARRAY];
	fstream read;
	read.open("DAYSO1.txt");
	read >> n;
	do{
		read >> i;
		a[inc++] = i;
	} while (!read.eof());
	
	for(i=0;i<inc;i++){
		for(int j=i+1;j<inc;j++){
			if(a[i] < a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout << "So lon nhat cua day la: " << a[0] << "\n";
	cout << "So lon thu hai cua day la: " << a[1] << "\n";
	
	cout << "Nhap k = ";
	cin >> k;
	cout << "So lon thu " << k << " cua day la: " << a[k-1] << "\n";
	
	read.close();
	return 0;
}
