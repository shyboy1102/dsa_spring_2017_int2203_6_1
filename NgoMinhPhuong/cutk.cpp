#include<bits/stdc++.h>

using namespace std;

int main(){
	
	ifstream readFile;
	readFile.open("DAYSO2.txt");
	vector<string> tmp;
	string line;
	
	if(readFile.is_open()){
		
		while(getline(readFile,line)){
			tmp.push_back(line);
		}
		
		readFile.close();
	}
	
	ofstream writeFile;
	int k;
	writeFile.open("KETQUA2.txt");
	cout << "Nhap k:" << endl;
	cin >> k;
	cin.ignore();
	
	vector<string> a ;
	vector<string> b;
	
	if(writeFile.is_open()){
		for(int i = 0 ; i < tmp.size() - k; i++){
			
			a.push_back(tmp[i]);
			
		}
		
		for(int j = tmp.size() - k; j < tmp.size() ; j++){
			
			b.push_back(tmp[j]);
		}
	}
	
	for(int i = 0 ; i < b.size() ;i++){
		
		writeFile << b[i] << endl;
		
	}
	for(int i = 0 ; i < a.size() ;i++){
		
		writeFile << a[i] <<endl;
		
	}
	
	return 0;
	
}
