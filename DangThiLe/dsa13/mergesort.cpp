#include<iostream>
#include<fstream>

using namespace std;

void printArray(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void merge(int a[], int l, int m, int r){
// Khoi tao 2 mang left , right
	int n_left = m - l + 1;
	int n_right = r - m;
	int left[n_left];
	int right[n_right];
	
// copy vao left, right
	for (int i = 0; i < m - l +1; i++)
		left[i] = a[l + i];
			
	for (int i = 0; i < r -m; i++)
		right[i] = a[m + 1 + i];
// sap xep
	int i = 0;
	int j = 0;
	int k = l;
	while(i < n_left && j < n_right){
		if(left[i] < right[j]){
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
		k++;
	}	
	while (i < n_left){
		a[k] = left[i];
		i++;
		k++;
	}
	while (j < n_right){ 
		a[k] = right[j];
		j++;
		k++;
	}
}
void merge_sort(int a[], int l, int r){
	if(l < r){
		int m = (l + (r-l))/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
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
	merge_sort(a, 0, n-1);
	cout << "After sorting: " << endl;
	printArray(a, n);
	ofstream f1;
	f1.open("output1.txt");
	for(i = 0; i < n ; i++){
        f1 << a[i] << endl;
    }
    
    f1.close();
	
	return 0;
}
