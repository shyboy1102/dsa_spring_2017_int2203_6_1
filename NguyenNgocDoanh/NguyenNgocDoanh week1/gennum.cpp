#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(){
	
	fstream wf; // write to file
	
	wf.open("DAYSO1.txt");
	
	int i = rand();
	
	wf << i << "\n";
	
	for(int j=0;j<i;j++)
		wf << rand() << "\n";
	
	wf.close();
	
	return 0;
}
