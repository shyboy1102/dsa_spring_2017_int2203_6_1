#include<bits/stdc++.h>

using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

void merge(int arr[], int l, int mi, int r)
{
    int n1 = mi-l+1;
    int n2 = r-mi;
    int tmp1[n1],tmp2[n2];
    int t,m;
    t = 0;
    m = 0;
    int k = l;
    for(int i = 0 ; i < n1 ; i++)
    {
        tmp1[i] = arr[l+i];
    }
    for(int j = 0 ; j < n2 ; j++)
    {
        tmp2[j] = arr[j+mi+1];
    }

    while(t < n1 && m < n2)
    {
        if(tmp1[t] <= tmp2[m])
        {
            cout << tmp1[t] << endl;
            arr[k] = tmp1[t];
            t++;

        }
        else
        {
            cout << tmp2[m] << endl;
            arr[k] = tmp2[m];
            m++;

        }
        k++;
    }

    while(t < n1)
    {
        arr[k] = tmp1[t];
        k++;
        t++;
    }
    while(m < n2)
    {
        arr[k] = tmp1[m];
        k++;
        m++;
    }
}

void sort(int arr[], int l, int r)
{

    if(l < r)
    {
        int m = l+(r+l)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void print(int arr[], int s)
{

    for(int i = 0 ; i < s ; i++)
    {
        cout << arr[i] << ',';
    }
}


int main()
{
    int arr[] = {12, 11, 13, 5, 6,7};
    int s = my_sizeof(arr)/my_sizeof(arr[0]);
    sort(arr,0,s-1);
    print(arr,s);

}
