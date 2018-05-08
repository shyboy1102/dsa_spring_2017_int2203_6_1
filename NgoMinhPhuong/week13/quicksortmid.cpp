#include<bits/stdc++.h>>

using namespace std;

void quicksortmid(int arr[] , int s , int e){

    int pivot = arr[s+(e-s)/2];
    int i = s , j = e;
    if(i>j)
        return;

    while(i<=j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
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
    quicksortmid(arr,0,s-1);
    print(arr,s);
}
