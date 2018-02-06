#include <iostream>
using namespace std;

double * setArray(int n){
    static double a[1000];
    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    return a;
}
void max_min(int n, double *a){
    int m=n/2,i;
    int imax,imin;
    double max,min;
    if(a[0] > a[1]){
        max = a[0];
        min = a[1];
    }
    else{
        max = a[1];
        min = a[0];
    }
    for(i=1; i < m; i++){
        if(a[2*i] > a[2*i+1]){
            imax = a[2*i];
            imin = a[2*i+1];
        }
        else{
            imax = a[2*i+1];
            imin = a[2*i];
        }
        max = (imax > max)?imax:max;
        min = (imin < min)?imin:min;
    }
    if(n == (2*m+1)){
        max = (a[n-1] > max)?a[n-1]:max;
        min = (a[n-1] < min)?a[n-1]:min;
    }

    cout << "Max=" << max <<endl;
    cout << "Min=" << min << endl;
}


int main(){
    int n;
    double *p;

    cout << "Nhap so phan tu n=";
    cin >> n;

    p=setArray(n);

    max_min(n,p);

    return 0;
}
