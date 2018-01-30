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
	outfile.open("KETQUA1.txt");
	vector<int> array;
	int n;
	while(infile >> n) {
		array.push_back(n);
	}
	cout << "Dang ghi file!" << endl;
	for(int i=array.size()-1;i>=0;i--) {
        outfile << array[i] << endl;
    }
    cout << "End!";
	infile.close();
	outfile.close();
	getch();
	return 0;
}

