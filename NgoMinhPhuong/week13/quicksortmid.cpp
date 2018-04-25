#include<bits/stdc++.h>>

using namespace std;

void quicksortmid(int arr[] , int s , int e){

    int pivot = arr[(s+e)/2];
    int i = s , j = e;
    if(i>j)
        return;

    while(i<=j){
        if(arr[i]<pivot){
            i++;
        }
        if(arr[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    quicksortmid(arr,s,j);
    quicksortmid(arr,i,e);

}
void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    cout << A[i] << "  ";
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7 ,12,3,4,6,3,7};
    int s = sizeof(arr)/sizeof(arr[0]);
    quicksortmid(arr,0,12);
    print(arr,s);
}
