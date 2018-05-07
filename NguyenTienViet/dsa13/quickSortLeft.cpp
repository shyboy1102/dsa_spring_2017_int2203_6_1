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

void quickSortLeft(int ar[], int left, int right){
    if (left >= right) return;

    int curLeft = left+1, curRight = right;
    int key = left;
    int i, j;

    while (curLeft < curRight){
        while (ar[curLeft] < ar[key]){
            curLeft++;
        }

        while (ar[curRight] > ar[key]){
            curRight--;
        }

        if (curLeft < curRight){
            Swap(ar,curLeft,curRight);
            curLeft++;
            curRight--;
        }
    }
    if (curLeft>curRight) {
        Swap(ar,key,curRight);
        key = curRight;
    }
    else{
        if (ar[key] < ar[curLeft]){
            Swap(ar,key,curLeft-1);
            key = curLeft-1;
        }
        else{
            Swap(ar,key,curLeft);
            key = curLeft;
        }
    }

    quickSortLeft(ar, left, key);
    quickSortLeft(ar, key+1, right);
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

    quickSortLeft(ar,0,8);
    printArray(ar,9);

    ofstream f1;
    f1.open("output2.txt");
    for(i = 0; i < n - 1; i++){
        f1 << ar[i] << endl;
    }
    f1 << ar[n-1];
    f1.close();
    return 0;
}
