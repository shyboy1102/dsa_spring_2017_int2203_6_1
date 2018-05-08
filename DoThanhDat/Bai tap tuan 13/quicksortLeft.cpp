#include <iostream>
#include <fstream>
using namespace std;

void swap(int a[], int n, int m){
    int tmp;
    tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}
int sort(int a[],int f,int l){
    int key = a[f];
    int i=f;
    for(int j=f+1; j <= l; j++){
        if(a[j] < key){
            i++;
            swap(a,j,i);
        }
    }
    swap(a,f,i);
    return i;
}
void quicksortleft(int a[], int f, int l){
    if(f < l){
        int mid = sort(a,f,l);
        quicksortleft(a,f,mid-1);
        quicksortleft(a,mid+1,l);
    }
}
int main(){
    int a[] = {2,6,3,7,4,5,1};
    fstream file("Text.txt");
    ofstream file2("Text2.txt");
    int n=0;
    int b[100];
//Doc file
    while(!file.eof()){
        file >> b[n];
        n++;
    }

    quicksortleft(b,0,n-1);
    quicksortleft(a,0,6);
//Ghi file2
    for(int i=0; i < n; i++)
        file2 << b[i] << endl;

    cout << "B:" << endl;
    for(int i=0; i < n; i++)
        cout << b[i] << endl;
    cout << "A:" << endl;
    for(int i=0;i<7;i++)
        cout << a[i] << endl;

    file.close();
    file2.close();
    return 0;
}
