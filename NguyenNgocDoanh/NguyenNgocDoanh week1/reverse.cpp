#include <iostream>
#include <fstream>

using namespace std;

#define MAX_ARRAY 10000

int main(){
	int a[MAX_ARRAY];
	int inc = 0,i;
	fstream rf; // read from file
	rf.open("DAYSO2.txt");
	while(!rf.eof() && (inc < MAX_ARRAY)){
		rf >> i;
		a[inc++] = i;
	}
	
	fstream wf; // write to file
	wf.open("KETQUA1.txt");
	for(int i=inc-1;i>=0;i--)
		wf << a[i] << "\n";
	rf.close();
	wf.close();
	return 0;
}
