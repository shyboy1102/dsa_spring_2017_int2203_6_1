#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> Q;

    Q.push(10);
    Q.push(5);
    while(!Q.empty()){
        cout << Q.front() << endl;
        Q.pop();
    }
    Q.pop(); //Khong con phan tu de xoa
    Q.push(2);
    cout << (Q.empty()?"Empty":"Not empty") << endl;
    cout << "Size=" << Q.size();

    return 0;
}
