#include<iostream>

using namespace std;

class Node{
    Node(){
        next = nullptr;
    }
    int data;
    Node * next;
    friend class ListStack;
};

class ListStack{
public:
    ListStack(){
        S = nullptr;
        n = 0;
    };
    int size() const{
        return n;
    }
    bool empty() const{
        return(!S);
    }
    const int & top() const{
        return S->data;
    }
    void push(int e){
        Node * t = new Node;
        t -> data = e;
        t -> next = S;
        S = t;
        n++;
    }
    void pop(){
        if (!S){
            cout << "danh sach rong" << endl;
            return;
        }
        Node * t = S;
        S = S->next;
        delete t;
        n--;
    }
private:
    Node * S;
    int n;
};

string decimalToBinery(const int n){
    ListStack myStack;
    int x = n;
    while(x != 0){
        myStack.push(x % 2);
        x = x / 2;
    }
    string s = "";
    while(!myStack.empty()){
        if(myStack.top()){
            s = s + "1";
        }
        else{
            s = s + "0";
        }
        myStack.pop();
    }
    return s;
}
int main(){

    cout << decimalToBinery(5);
    return 0;
}
