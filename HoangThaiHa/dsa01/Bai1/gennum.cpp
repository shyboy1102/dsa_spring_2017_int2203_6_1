#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main () 
{ 
	ofstream outfile;
	outfile.open("DAYSO1.txt");
	cout << "WRITING.........." <<  endl;
	cout << "\n===========================\n" << endl;
	srand(time(NULL));
	int n = rand();
	outfile << n << endl;
	for(int i=0; i < n; i++) {
		outfile << rand() << endl;
	}
	outfile.close();
	cout << "SUCCESS!"<< endl;
	getch();
	return 0;
}
