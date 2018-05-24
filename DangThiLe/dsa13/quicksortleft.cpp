#include<iostream>
#include<fstream>

using namespace std;

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
void quicksortleft(int a[], int l, int r){
	if(l >= r)
		return;
	int i = l, j = r, key = l;
	while(i < j){
		while(a[i] < key) i++;
		while(a[j] > key) j--;
		if(i < j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(i > j){
		swap(a[key],a[j]);
		key = j;
	}
	else{
		if(a[key] < a[l]){
			swap(a[key], a[i-1]);
			key = i - 1;
		}
		else{
			swap(a[key], a[i]);
			key = i;
		}
	}
	quicksortleft(a, l, key);
	quicksortleft(a, key+1, r);
}
int main(){
	ifstream f;
	f.open("input.txt");
	int a[100], i = 0, n = 0;
	while (!f.eof()){
		f >> a[i];
		i++;
		n++;
	}
	f.close();
	
	cout << "Before sorting: " << endl;
	printArray(a, n);
	quicksortleft(a, 0, n-1);
	printArray(a, n);
	ofstream f1;
	f1.open("output4.txt");
	for(i = 0; i < n ; i++){
        f1 << a[i] << endl;
    }
    
    f1.close();
	
	return 0;
    return 0;
	
	
}
