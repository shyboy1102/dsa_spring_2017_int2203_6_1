#include<bits/stdc++.h>
#include <string>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


void print(int arr[], int s)
{
    int i;
    for (i=0; i < s; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


int main()
{
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
    for(int i = 0 ; i < k.size(); i++){
        arr[i] = k[i];
    }
    int s = k.size();
    print(arr, s);

    mergeSort(arr, 0, s - 1);

    cout<< "sorted:";
    print(arr, s);
    return 0;
}
