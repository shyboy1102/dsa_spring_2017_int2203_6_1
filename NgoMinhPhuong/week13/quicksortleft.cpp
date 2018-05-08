#include<bits/stdc++.h>>

using namespace std;

void quicksortleft(int arr[] , int s , int e){

    int pivot = arr[s];
    int i = s+1 , j = e;
    if(i>j)
        return;

    while(i<=j){
        if(arr[i]<=pivot){
            i++;
        }
        if(arr[j]>=pivot){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
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
    vector<int> k;
    ifstream input;
    input.open("input.txt");
    if(input.is_open()){
        while (!input.eof()){
            string tmp;
            input >> tmp;
            k.push_back(atoi(tmp.c_str()));
        }
    }

    int arr[k.size()];
    int s = k.size();
    for(int i = 0 ; i < k.size(); i++){
        arr[i] = k[i];
    }
    print(arr,s);
    cout << endl;
    cout<< "sorted:" ;
    quicksortleft(arr,0,s-1);
    print(arr,s);
}
