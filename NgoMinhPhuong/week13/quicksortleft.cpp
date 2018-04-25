#include<bits/stdc++.h>>

using namespace std;

void quicksortleft(int arr[] , int s , int e){

    int pivot = arr[s];
    int i = s+1 , j = e;
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
    swap(arr[s],arr[j]);
    quicksortleft(arr,s,j-1);
    quicksortleft(arr,j+1,e);

}
void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    cout << A[i] << "  ";
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7 , 13 , 8, 9};
    int s = sizeof(arr)/sizeof(arr[0]);
    quicksortleft(arr,0,8);
    print(arr,s);
}
