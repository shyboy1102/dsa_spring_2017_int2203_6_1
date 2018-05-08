#include <iostream>
#include <fstream>
using namespace std;

void swap(int a[], int n, int m){
    int tmp;
    tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}
void sort(int a[], int n, int i){
    int key = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && a[l] > a[key])
        key = l;
    if(r < n && a[r] > a[key])
        key = r;
    if(key != i){
        swap(a,i,key);
        sort(a,n,key);
    }
    return;
}
void heapsort(int a[], int n){
    for(int i=n/2-1; i >= 0; i--)
        sort(a,n,i);
    for(int i=n-1; i >= 0; i--){
        swap(a,0,i);
        sort(a,i,0);
    }
}
int main(){
    int a[]={2,3,5,6,4,1,7,8,30};
    int n = sizeof(a)/sizeof(a[0]);
    int m=0,b[100];

    fstream file("Text.txt");
    while(!file.eof()){
        file >> b[m];
        m++;
    }
    heapsort(b,m);
    heapsort(a,n);
    cout << "A:" << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << endl;
    }
    cout << "B:" << endl;
    for(int i=0; i < m; i++){
        cout << b[i] << endl;
    }
    return 0;
}
