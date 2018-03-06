#include <iostream>
#include <fstream>
using namespace std;

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main(){
    ifstream file("DAYSO1.txt");
    int n;
    file >> n;
    cout << n << endl;
    int num[n];
    for(int i=0; i < n; i++){
        file >> num[i];
        cout << num[i] << endl;
    }

    for(int i = 0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if(num[i] < num[j])
                swap(num[i],num[j]);
        }
    }

    int k;
    cout << "So nguyen lon thu k=";
    cin >> k;
    if(k <= n)
        cout << num[k-1];

    file.close();

    return 0;
}
