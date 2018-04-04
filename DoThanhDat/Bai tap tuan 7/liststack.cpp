#include <iostream>
#include <string>
using namespace std;

class Node{
    int data;
    Node *next;
    friend class ListStack;
};
class ListStack{
public:
    ListStack();
    int size() const;
    bool empty() const;
    const int &top() const;
    void push(int e);
    int  pop();
    void print();
private:
    Node *S;
    int n;
};

ListStack::ListStack(){
    S = NULL;
    n = 0;
}
int ListStack::size() const{
    return n;
}
bool ListStack::empty() const{
    if(S == NULL)
        return true;
    else
        return false;
}
const int& ListStack::top() const{
    return S->data;
}
void ListStack::push(int e){
    Node *N = new Node();
    N->data = e;
    if(n == 0){
        N->next = NULL;
        S = N;
    }
    else{
        N->next = S;
        S = N;
    }
    n++;
}
int ListStack::pop(){
    int pop = S->data;
    if(!empty()){
        S = S->next;
        n--;
    }
    else
        cout << "Xoa het roi";
    return pop;
}
void ListStack::print(){
    while(!empty()){
        cout << S->data << endl;
        pop();
    }
}
string decimalToBinary(int n){
    ListStack lt;
    while (n != 0){
        lt.push(n%2);
        n = n/2;
    }
    string str;
    while(!lt.empty()){
        str += std::to_string(lt.pop());
    }
    return str;
}

int main(){
    ListStack lt;

    for(int i=1; i < 4; i++)
        lt.push(i);
    cout << "Size1=" << lt.size() << endl;
    cout << "Pop=" << lt.pop() << endl;
    lt.print();
    cout << "Convert:" << decimalToBinary(20);

    return 0;
}
