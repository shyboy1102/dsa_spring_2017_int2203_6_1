#include<iostream>
using namespace std;

int main()
{
    int a[100][100];
    int i,j,n,k=0,max;
    cout  <<  "Nhap cap cua ma tran: n=";
    cin  >>  n;

    for(i = 0; i < n; i++){
        for(j=0;j<n;j++){
            cout<<"a["<<i<<"]"<<"["<<j<<"]=";
            cin >> a[i][j];
        }
    }
    cout << "Ma tran vua tao:" << endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"  ";
            cout<<"\t";
        }
        cout << "\n";
    }
    i=0;j=0;
    while(1){
        cout << "i=" << i << ",j=" << j << endl;
        if(a[i][j] == 0){
           i++;
        }
        else{
            j++;
            max = i;
       //     if(a[i][j-1] == 1 && a[i][j] == 0){
       //         k++;
        //        max[k] = i;
        //        }
            }
        if(i == n && j == n)
            break;
    }
    cout<<""Hang chua nhieu so 1 nhat la hang thu:"<<max + 1;
    return 0;
}
