#include<iostream>

using namespace std;

int main(){
    unsigned int n;
    float x,t,s;
    cout << "Nhap co so x = ";
    cin >> x;
    cout << "Nhap so mu n = ";
    cin >> n;

    int i = 0;
    int a[100];

    while (n != 0){
        a[i] = n % 2;
        n = n / 2;
        i++;
    }
    int k = i;

    t = x;
    s = 1;
    for(i = 0; i < k; i++){
        if (a[i] == 1){
            s = s * t;
        }
        t = t * t;
    }

    cout << "power(x,n) = " << s;
    return 0;
}
