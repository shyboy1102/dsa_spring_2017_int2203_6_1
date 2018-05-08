#include<iostream>
#include<fstream>
using namespace std;

#define MAX_ARRAY 10000

int parent(int i){
	return (i/2);
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

void swap(int * x, int * y){
	int * t = x;
	x = y;
	y = t;
}

void Max_Heapify(int A[], int i, int n){
	int l = left(i);
	int r = right(i);
	int largest;

	if(l <= n && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if(r <= n && A[r] > A[largest])
		largest = r;

	if(largest != i){
		swap(A[i], A[largest]);
		Max_Heapify(A, largest, n);
	}
}


void BuildMaxHeap(int A[], int n){
	for(int i = n/2;i>0;i--)
	//for(int i=1;i<=n/2;i++)
		Max_Heapify(A, i, n);
}

void Heap_Sort(int A[], int n){
	BuildMaxHeap(A, n);
	int size_heap = n;
	for(int i=n;i>1;i--){
		swap(A[1], A[i]);
		size_heap--;
		Max_Heapify(A, 1, size_heap);
	}
}


int main(){
	int A[MAX_ARRAY];
	int n=0;

	ifstream i_file("input.txt");
	while(!i_file.eof()){
		i_file >> A[++n];
	}
	
	Heap_Sort(A, n);

	ofstream o_file("output.txt");
	for(int i=1;i<=n;i++)
		o_file << A[i] << endl;

	o_file.close();
	i_file.close();
	return 0;
}