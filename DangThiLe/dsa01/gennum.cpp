#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
	int n = rand()%1000;
	int a[n],i;
	ofstream outfile;
	outfile.open("DAYSO1.txt");
	outfile << n << "\n";
	for(i=0; i<n; i++){
		a[i] = rand();
		outfile << a[i] << endl;
	}
	outfile.close();
	return 0;
}
