#include <iostream>
#include <fstream>
using namespace std;

void merger(int a[], int f, int mid, int l){
    int n1,n2,f1,f2,index;
    n1 = mid-f+1;
    n2 = l-mid;

    int atem1[n1],atem2[n2];

    for(int i=0; i < n1; i++)
        atem1[i] = a[i+f];
    for(int i=0; i < n2; i++)
        atem2[i] = a[i+mid+1];

    f1=0;
    f2=0;
    index=f;
    while(f1 < n1 && f2 < n2){
        if(atem1[f1] <= atem2[f2]){
          a[index] = atem1[f1];
          index++;
          f1++;
        }
        else{
            a[index] = atem2[f2];
            index++;
            f2++;
        }
    }
    while(f1 < n1){
        a[index] = atem1[f1];
        index++;
        f1++;
    }
    while(f2 < n2){
        a[index] = atem2[f2];
        index++;
        f2++;
    }
}
void mergesort(int a[],int f,int l){
    if(f < l){
        int mid = (f+l)/2;
        mergesort(a,f,mid);
        mergesort(a,mid+1,l);
        merger(a,f,mid,l);
    }
}
int main(){
    int a[] = {38,27,43,3,9,82,10,23};
    //Doc file
    fstream file("Text.txt");
    int n=0;
    int b[100];

    while(!file.eof()){
        file >> b[n];
        n++;
    }

    mergesort(b,0,n-1);
    mergesort(a,0,7);
    cout << "b:" << endl;
    for(int i=0; i < n ;i++)
        cout << b[i] << endl;
    cout << "a:" << endl;
    for(int i=0; i < 8; i++)
        cout << a[i] << endl;

    file.close();
    return 0;
}
