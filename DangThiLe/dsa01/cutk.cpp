#include <iostream>
#include <fstream>

using namespace std;

int main()  {
	int n=0, a[1000];
	int k;
	cin >> k;
    std::ifstream fileInput("DAYSO2.txt");
	while (!fileInput.eof()){
			int j;
			fileInput >> j;
			a[n] = j;
			n++;
	}
	fileInput.close();
	ofstream outfile;
	outfile.open("KETQUA2.txt");
	//outfile << n << "\n";
	for(int i=k; i<n-1; i++){
		
		outfile << a[i] << endl;
	}
	for(int i=0; i<k; i++){
		
		outfile << a[i] << endl;
	}
	outfile.close();
	return 0;
}
