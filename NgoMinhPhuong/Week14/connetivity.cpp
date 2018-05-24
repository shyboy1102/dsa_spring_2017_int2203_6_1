#include<bits/stdc++.h>
#include <string>

using namespace std;

int main(){
	ifstream  file("graph1.txt");
	string count;
	file >> count;
	int	n = atoi(count.c_str());
	int tmp[n][n];
	for(int i= 0 ; i < n ; i++){
		for(int j= 0 ; j < n ; j++){
			file >> tmp[i][j];		
		}
	}
	int s_index;
	cin >> s_index;
	ofstream outfile ("output1.txt");
	outfile <<"s=" << s_index << endl;
	for(int i = 0 ; i < n ;i++){
		if(tmp[s_index][i]==1){
			outfile <<tmp[s_index][i] << " ";
		}
	}
	return 0;
}
