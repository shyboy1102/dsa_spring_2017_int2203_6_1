#include <iostream>
#include <fstream>
using namespace std;
void swap(int a[],int n,int m){
    int tmp;
    tmp = a[n];
    a[n] = a[m];
    a[m] = tmp;
}
void quicksortMid(int a[] ,int f, int l){
    int n1=f,n2=l;
    int key = a[(l+f)/2];
    while(n1<n2){
        while(a[n1] < key)
            n1++;
        while(a[n2] > key)
            n2--;
        if(n1 <= n2){
            swap(a,n1,n2);
            n1++;
            n2--;
        }
    }
    if(f < n2)
        quicksortMid(a,f,n2);
    if(l > n1)
        quicksortMid(a,n1,l);

}

int main(){
    int a[] = {2,6,3,7,4,5,1};
    fstream file("Text.txt");
    ofstream file3("Text3.txt");
    int n = 0;
    int b[100];
//Doc file
    while(!file.eof()){
        file >> b[n];
        n++;
    }

    quicksortMid(b,0,n-1);
    quicksortMid(a,0,6);
//Ghi file2
    for(int i=0; i < n; i++)
        file3 << b[i] << endl;

    cout << "B:" << endl;
    for(int i=0; i < n; i++)
        cout << b[i] << endl;
    cout << "A:" << endl;
    for(int i=0; i<7; i++)
        cout << a[i] << endl;

    file.close();
    file3.close();
    return 0;
}
