#include<iostream>
#include<fstream>

using namespace std;

void Swap(int ar[], int x, int y){
    int tamp = ar[x];
    ar[x] = ar[y];
    ar[y] = tamp;
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ",  ";
    }
    cout << endl;
}

void quickSortMid(int ar[], int left, int right){
    if (left >= right) return;

    int curLeft = left, curRight = right;
    int key = left + (right-left)/2;
    int i, j;
    while (curLeft < curRight){
        while (ar[curRight] > ar[key]){
            curRight--;
        }
        if(curRight > key){
            Swap(ar,curRight,key);
            key = curRight;
        }

        while (ar[curLeft] < ar[key]){
            curLeft++;
        }
        if(curLeft < key){
            Swap(ar,curLeft,key);
            key = curLeft;
        }
    }

    quickSortMid(ar, left, key-1);
    quickSortMid(ar, key+1, right);
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

    printArray(ar,n);
    quickSortMid(ar,0,8);
    printArray(ar,n);

    ofstream f1;
    f1.open("output3.txt");
    for(i = 0; i < n - 1; i++){
        f1 << ar[i] << endl;
    }
    f1 << ar[n-1];
    f1.close();
    return 0;
}
