#include <iostream>
using namespace std;

double p(double x, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n > 1){
        if(n%2==0)
            return p(x,n/2)*p(x,n/2);
        else
            return x*p(x,n/2)*p(x,n/2);
    }

int main(){
    double x;
    int n;
    cout << "x=";
    cin >> x;
    cout << "n=";
    cin >> n;

    cout << "Gia tri ham mu p:" << p(x,n);
    return 0;
}

