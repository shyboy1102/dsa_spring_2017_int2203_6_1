
#include<bits/stdc++.h>

using namespace std;

void sort(vector<int>& _array);

int main(){
	
	/* n random generation */
	
	srand(time(NULL));
	int n = rand(); 
	int count = 0;
	
	/*
	*
	* Bai 1.1
	*
	*/
	
	/* create out file */
	ofstream myFile;
	myFile.open("DAYSO1.txt");
	
	while(myFile.is_open()&&count<n){
		
		myFile << n << endl;
		int randVariable = rand();
		myFile << randVariable << endl;
		 ++count;
	}
	
	myFile.close();
	
	/*
	*
	* Bai 1.2
	*
	*/
	
		
	vector<int>array;
	ifstream cinMyFile;
	cinMyFile.open("DAYSO1.txt");
	
	
	if(cinMyFile.is_open()){
	
		string line;
		while (getline(cinMyFile,line)){
		
		int tmp;
		stringstream s_tmp (line);
		s_tmp >> tmp;
		array.push_back(tmp);
			
		}
		
	cinMyFile.close();		
	
	}
	
	sort(array);
	cout << "So lon nhat :"<<array[array.size()-1] << endl;
	cout << "So lon thu hai :"<<array[array.size()-2] << endl;
	cout << "Nhap vao so k :" << endl;
	int k;
	cin >> k ;
	cin.ignore();
	cout << "So lon thu k la :" << array[array.size()-k] << endl; 
	
	
	
	

	
	return 0;
	
}

/*
*
*Sort the array be increase
*
*/

void sort(vector<int>& _array){
	int tmp;
	
	for(int i = 1 ; i < _array.size() ; i++){
		
		for(int j = i+1 ; j < _array.size() ; j++){
			
			if(_array[i] > _array[j]){
				
				 tmp = _array[i];
				_array[i] = _array[j];
				_array[j] = tmp; 
				
			}
		}
	}	

}
