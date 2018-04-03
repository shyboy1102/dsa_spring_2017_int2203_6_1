#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node{
    int data;
    Node * next;
    friend class ListStack;
};

class ListStack {
public:
    ListStack();
    int size() const;
    bool empty() const;
    const int & top() const;
    void push(int e);
    int pop();
    string toString();
    string decimalToBinary(int n);
private:
    Node * S;
    int n;
};

    ListStack::ListStack() {
        S = NULL;
        n = 0;
    }

    int ListStack::size() const {
        return n;
    }

    bool ListStack::empty() const {
        return n == 0;
    }

    const int& ListStack::top() const {
        return S->data;
    }

    void ListStack::push(int e) {
        Node * q = new Node();
        q->data = e;
        q->next = NULL;
        if(empty()) {
            S = q;
        }
        else {
            q->next = S;
            S = q;
        }
        n++;
    }

    int ListStack::pop() {
        if(!empty()) {
            n --;
            Node * q = S;
            int x = q->data;
            q = q->next;
            delete S;
            S = q;
            return x;
        }
    }

    string ListStack::toString() {
        string result = "";
        while(!empty()) {
            ostringstream convert;
            convert << pop();
            result += convert.str();
        }
        return result;
    }

    string ListStack::decimalToBinary(int n) {
        ListStack temp;
        while(n) {
            temp.push(n%2);
            n /= 2;
        }
        return temp.toString();
    }

int main() {
    ListStack myls;
    myls.push(3);
    myls.push(5);

    cout << (myls.empty()? "true" : "false") << endl;

    cout << myls.top() << endl;
    myls.pop();
    cout << myls.top() << endl;

    cout << myls.size() << endl;

    int x = 9;
    cout << x << " = " << myls.decimalToBinary(x) << endl;
    return 0;
}
