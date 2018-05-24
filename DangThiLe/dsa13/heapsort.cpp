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
void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i +2;
	if(l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if(largest != i){
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n){
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for(int i = n - 1; i >= 0; i--){
		swap(a[0], a[i]);
		heapify(a, i, 0);
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
	heapsort(a, n);
	printArray(a, n);
	ofstream f1;
	f1.open("output4.txt");
	for(i = 0; i < n ; i++){
        f1 << a[i] << endl;
    }
    
    f1.close();
	
	return 0;
}
