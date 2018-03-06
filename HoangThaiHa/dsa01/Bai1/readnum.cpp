#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void sort(int a[], int length) {
    int i, j;
    int temp;
    for (i=0;i<length-1;i++) {
        for(j=i+1;j<length; j++) {
            if(a[i]<a[j]) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
int main() {
	ifstream infile;
	infile.open("DAYSO1.txt");
	cout << "\n===========================\n" ;
	cout << "Doc du lieu co trong file!" << endl; 
	int i = 0, length, temp;	
	infile >> length; 
	int listNumber[length];
	int listDistinct[length];
	while(infile >> temp) {
		listNumber[i++] = temp;
	}
	sort(listNumber,length);
	listDistinct[0] = listNumber[0];
	int last = listDistinct[0];
	int x = 0;
	for (i = 1; i < length; i++) {
		if (listNumber[i] != last) {
			listDistinct[++x] = listNumber[i];
			last = listNumber[i];
		}
	}
	cout << "So lon nhat la: " << listDistinct[0] << endl;
    cout << "So lon thu hai la: " << listDistinct[1] << endl;
    int k;
     while(k<=0||k>length) {
        cout << "Nhap vao k: ";
        cin >> k;
    }
    cout << "So lon thu " << k << ": " << listDistinct[k-1] << endl;

	infile.close();
	getch();
	return 0;
}

