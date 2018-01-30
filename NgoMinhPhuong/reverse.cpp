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
	writeFile.open("KETQUA1.txt");
	
	if(writeFile.is_open()){
		for(int i = tmp.size()- 1; i!= 0 ; i--){
			
			writeFile << tmp[i] << endl;
			
		}
	}
	
}
