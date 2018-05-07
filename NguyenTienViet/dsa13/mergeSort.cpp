#include<iostream>
#include<fstream>

using namespace std;

void mergeSubArray(int a[], int x, int y, int u, int v){
    //bien luu tru do dai 2 mang con
    int n1 = y - x + 1;
    int n2 = v - u + 1;

    //tao 2 mang tam nhieu hon 2 mang cạn merge 1 phan tu
    int a1[n1 + 1], a2[n2 + 1];

    int i,j,k;

    //sao chep du lieu
    for(i = 0; i < n1; i++){
        a1[i] = a[x+i];
    }
    for(i = 0; i < n2; i++){
        a2[i] = a[u+i];
    }

    //tao 2 phan tu cuoi cung cua 2 mang de lam chot cho vong merge
    a1[n1] = a2[n2-1] + 1;
    a2[n2] = a1[n1-1] + 1;

    //merge
    for(k = x, i = 0, j = 0; k <= v; k++){
        if(a1[i] < a2[j]){
            a[k] = a1[i];
            i++;
        }
        else{
            a[k] = a2[j];
            j++;
        }
    }
}

void mergeSort(int a[], int l, int r){
    //truong hop co so
    if (l == r) return;
    //chia 2 day con va sap xep
    int m = l + (r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);

    //gop 2 day con
    mergeSubArray(a,l,m,m+1,r);
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ",  ";
    }
    cout << endl;
}

int main(){
    ifstream f;
    f.open("input.txt");
    int ar[1000];
    int i = 0, n = 0;
    while(!f.eof()){
        f >> ar[i];
        i++;
        n++;
    }
    f.close();

    mergeSort(ar,0,n-1);
    printArray(ar,n);

    ofstream f1;
    f1.open("output1.txt");
    for(i = 0; i < n - 1; i++){
        f1 << ar[i] << endl;
    }
    f1 << ar[n-1];
    f1.close();

    return 0;
}
