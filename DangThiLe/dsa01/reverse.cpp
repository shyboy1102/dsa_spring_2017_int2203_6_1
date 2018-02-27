#include <iostream>
#include <fstream>

using namespace std;

int main()  {
	int i=0, a[1000];
	std::ifstream fileInput("DAYSO2.txt");
	while (!fileInput.eof()){
			int n;
			fileInput >> n;
			a[i] = n;
			i++;
	}
	
	ofstream outfile;
	outfile.open("KETQUA1.txt");
	
	for(int j = i-2; j >= 0; j--){
		
		outfile << a[j] << endl;
	}
	outfile.close();
	return 0;
}
