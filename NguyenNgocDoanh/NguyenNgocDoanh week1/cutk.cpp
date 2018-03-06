#include<fstream>
#include<iostream>

using namespace std;

#define MAX_ARRAY 10000

int main(){
	int n,i,k;
	int a[MAX_ARRAY];
	
	fstream fr; // read from file
	fr.open("DAYSO2.txt");
	while (!fr.eof() && (n < MAX_ARRAY)){
		fr >> i;
		a[n++] = i;
	}
	
	cout << "Nhap k =";
	cin >> k;
	if (k>n){
		cout << "Nhap lai k (0<k<=" << n << ")";
		cin >> k;	
	}
	
	fstream fw; // write to file
	fw.open("KETQUA2.txt");
	for(int i = k;i<n;i++) fw << a[i] << "\n";
	for(int i = 0;i<k;i++) fw << a[i] << "\n";
	fr.close();
	fw.close();
	return 0;
}
