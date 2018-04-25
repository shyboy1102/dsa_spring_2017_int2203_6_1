#include<bits/stdc++.h>
#include <time.h>

using namespace std;

void countersort(int arr[] , int n){
    int t = n*n-1;

    for(int i = 0 ;i < n ; i++){
        arr[i] = rand() % t + 1;
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] <<' ';
    }
    cout << endl;

    int c[t];

    for(int i = 0 ; i < t ; i++){
        c[i] = 0;
    }

    for(int i = 0 ; i < n ; i++){
        c[arr[i]]++;
    }
    int k = 0;
    for(int i = 0 ; i < t ; i++ ){
      while(c[i]!=0){
        arr[k] = i;
        k++;
        c[i] = c[i]-1;
      }
    }

}

int main(){
    srand (time(NULL));
    int n;
    cout << "input n?:" ;
    cin >>n;
    cout << endl;
    int arr[n];
    countersort(arr,n);
    cout << "sorted:" ;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] <<' ';
    }

}
