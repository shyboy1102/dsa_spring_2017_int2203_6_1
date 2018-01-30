#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include<vector>

using namespace std;
int main() {
	ifstream infile;
	infile.open("DAYSO2.txt");
	cout << "\n===========================\n" ;
	cout << "Doc du lieu co trong file!" << endl; 
	ofstream outfile;
	outfile.open("KETQUA2.txt");
	vector<int> array;
	int n;
	while(infile >> n) {
		array.push_back(n);
	}
	int count = array.size();
	int k;
	do {
		cout << "Nhap vao so K :" ;
		cin >> k;	
	}
	while (k < 0 || k > count); 
	cout << "Dang ghi file!" << endl;
	for(int i=k; i<count;i++) {
		outfile << array[i] << endl;
	}
	for(int i=0;i<k;i++) {
		outfile << array[i] << endl;
	}

	infile.close();
	outfile.close();
	getch();
	return 0;
}

