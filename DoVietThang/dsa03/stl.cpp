#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;

int main(){
    vector<int> a;
    for(int i = 1; i <= 3; i++) a.push_back(i);
    for(int i = 3; i <= 5; i++) a.push_back(i);
    cout << "A = 1, 2, 3, 3, 4, 5" << endl;
    if(a.empty()==0){
        cout << "empty(A) : " << "false" << endl;
    }
    else{
        cout << "empty(A) : " << a.empty() << endl;
    }
    cout << "length(A) -> " << a.size() << endl;
    cout << "element(A,0) -> " << a[0] << endl;
    cout << "element(A,2) -> " << a[2] << endl;

    a.insert(a.begin()+2,10);
    cout << "insert(A,2,10) -> A = " ;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;

    a.push_back(-5);
    cout << "append(A,-5) -> A = ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;

    a.erase(a.begin() + 3);
    cout << "del(A,3) -> A = ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;

    a.erase(a.begin() + 1);
    cout << "del(A,1) -> A = ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}
