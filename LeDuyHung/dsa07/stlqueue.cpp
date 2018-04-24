#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myqueue;

    myqueue.push(10);
    myqueue.push(5);

    cout << myqueue.front() << endl;

    myqueue.pop();

    cout << myqueue.size() << endl;

    myqueue.pop();

    if(myqueue.size() == 0) {
        cout << "Error: Empty queue" << endl;
    }
    else {
        cout << myqueue.front() << endl;
    }

    if(myqueue.size() == 0) {
        cout << "Error: Empty queue" << endl;
    }
    else {
        myqueue.pop();
    }

    cout << (myqueue.empty() ? "true" : "false") << endl;

    myqueue.push(8);

    return 0;
}
