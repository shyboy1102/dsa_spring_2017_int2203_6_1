#include <iostream>
using namespace std;

class EmptyQueueException{
public:
    string getMessage(){
        return "Error:Queue is empty";
    }
};

class ArrayQueue{
public:
    ArrayQueue();
    ~ArrayQueue();
    int size();
    bool isEmpty();
    int front() throw (EmptyQueueException);
    int rear() throw (EmptyQueueException);
    void enqueue(int x);
    void dequeue();
    void print();
private:
    bool isFull();
    int * element;
    int capacity;
    int f;
    int r;
};

ArrayQueue::ArrayQueue(){
    capacity = 2;
    element = new int[capacity];
    f = 0;
    r = 0;
}
ArrayQueue::~ArrayQueue(){
    delete[] element;
    element = NULL;
    capacity = 0;
    f = 0;
    r = 0;
}
int ArrayQueue::size(){
    return (capacity+r-f) % capacity;
}
bool ArrayQueue::isEmpty(){
    return (f == r);
}
bool ArrayQueue::isFull(){
    return (size() == capacity-1);
}
int ArrayQueue::front() throw (EmptyQueueException){
    if(isEmpty()) throw EmptyQueueException();
    return element[f];
}
int ArrayQueue::rear() throw (EmptyQueueException){
    if(isEmpty()) throw EmptyQueueException();
    return element[(capacity+r-1) % capacity];
}
void ArrayQueue::enqueue(int x){
    if(!isFull()){
        element[(capacity+r)%capacity] = x;
        r = (r+1)%capacity;
    }
    else{
        capacity = 2*capacity + 1;
        int *p = new int[capacity];
        int s = size();
        for(int i=f,j=0; j < s-1; i = (i+1)%capacity,j++){
            p[i] = element[i];
        }
        p[(capacity+r-1) % capacity] = element[(capacity+r-1) % capacity];
        p[(capacity+r)%capacity] = x;
        r = (r+1)%capacity;
        delete[] element;
        element = p;
    }
}
void ArrayQueue::dequeue(){
    if(f < size()){
        element[f] = 0;
        f = (f+1)%capacity;
    }
    else
        cout << "Xoa het roi" << endl;
}
void ArrayQueue::print(){
    cout << "(";
    int s = size();
    for(int i=f, j=0;j < s-1; i = (i+1)%capacity,j++){
        cout << element[i] << ",";
    }
    if(s > 0) cout << rear();
    cout << ")" << endl;
}

int main(){
    ArrayQueue Q;

    Q.dequeue();
    cout << "Size1=" << Q.size() << endl;

    Q.dequeue();
    Q.dequeue();
    cout << "Size2=" << Q.size();

    Q.print();

    return 0;
}
