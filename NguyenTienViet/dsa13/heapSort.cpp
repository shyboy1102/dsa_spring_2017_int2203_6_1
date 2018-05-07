#include<iostream>
#include<fstream>

using namespace std;

void Swap(int ar[], int x, int y){
    int tamp = ar[x];
    ar[x] = ar[y];
    ar[y] = tamp;
}

void printArray(int a[], int n){
    for(int i = 1; i <= n; i++){
        cout << a[i] << ",  ";
    }
    cout << endl;
}

void fixNode(int ar[], int node, int n){
    if((2*node+1) > n){
        if(ar[2*node] > ar[node]){
            Swap(ar,2*node,node);
        }
        return;
    }
    if(ar[2*node] > ar[2*node+1] && ar[2*node] > ar[node]){
        Swap(ar,2*node,node);
        return;
    }
    if(ar[2*node+1] > ar[2*node] && ar[2*node+1] > ar[node]){
        Swap(ar,2*node+1,node);
        return;
    }
}

void heapSort(int ar[], int n){
    if (n == 1) {
        return;
    }
    int i;
    for(i = n/2; i >= 1; i--){
        fixNode(ar,i,n);
    }
    Swap(ar,1,n);
    heapSort(ar,n-1);
}


int main(){

    ifstream f;
    f.open("input.txt");
    int ar[1000];
    int i = 1, n = 0;
    while(!f.eof()){
        f >> ar[i];
        i++;
        n++;
    }
    f.close();
    printArray(ar,9);
    heapSort(ar,9);
    printArray(ar,9);

    ofstream f1;
    f1.open("output4.txt");
    for(i = 0; i < n - 1; i++){
        f1 << ar[i] << endl;
    }
    f1 << ar[n-1];
    f1.close();
    return 0;
}

