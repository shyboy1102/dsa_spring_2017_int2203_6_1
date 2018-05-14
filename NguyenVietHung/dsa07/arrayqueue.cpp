#include <iostream>
using namespace std;
#define INIT_CAPACITY 2

class EmptyQueueException{
public:
    string getMessage() {
        return "Hang doi rong.";};
};

class ArrayQueue {
public:
    ArrayQueue();// ham kien tao
    ~ArrayQueue();// ham huy
    int size();// ham dem so phan tu trong hang doi
    bool isEmpty();// ham kiem tra hang doi rong
    int front() throw (EmptyQueueException);// ham tra ve gia tri phan tu o dau hang doi
    int rear() throw (EmptyQueueException);// ham tra ve gia tri phan tu o cuoi hang doi
    void enqueue(int x);// ham them x vao cuoi hang doi
    int dequeue() throw (EmptyQueueException);// ham loai phan tu o dau hang doi
    void print();// ham in hang doi
private:
    bool isFull();// ham kiem tra xem mang day hay chua
    int * element;// con tro toi dau mang
    int capacity;// kich thuoc toi da cua mang
    int f;// chi so cua o dau hang doi
    int r;// chi so cua o lien sau o cuoi hang doi
};

ArrayQueue::ArrayQueue() {
    capacity = INIT_CAPACITY;
    element = new int[capacity];
    f = 0;
    r = 0;
}

ArrayQueue::~ArrayQueue() {
    delete [] element;
    element = NULL;
    capacity = 0;
    f = 0;
    r = 0;
}

int ArrayQueue::size() {
    return (capacity + r - f) % capacity;
}

bool ArrayQueue::isEmpty() {
    return (f == r);
}

bool ArrayQueue::isFull() {
    return (size() == capacity - 1);
}

int ArrayQueue::front() throw (EmptyQueueException) {
    if(isEmpty()) throw EmptyQueueException();
    return element[f];
}

int ArrayQueue::rear() throw (EmptyQueueException) {
    if(isEmpty()) throw EmptyQueueException();
    return element[(capacity + r - 1) % capacity];
}

void ArrayQueue::print(){
    cout << "(";
    int s = size();
    for(int i = f, j = 0; j < s - 1; i = (i + 1) % capacity, j++) {
        cout << element[i] << ", ";
    }
    if(s > 0) cout << rear();
    cout << ")" << endl;
}

void ArrayQueue::enqueue(int x) {
    if(isFull()) {
        capacity *= 2;
    }
    element[r] = x;
    r = (r+1) % capacity;
}

int ArrayQueue::dequeue() throw (EmptyQueueException) {
    if(isEmpty()) {
        throw EmptyQueueException();
    }
    else {
        int x = element[f];
        f = (f + 1) % capacity;
        return x;
    }
}

int main() {
    ArrayQueue myqueue;
    myqueue.enqueue(1);
    myqueue.enqueue(2);
    myqueue.enqueue(3);
    myqueue.print();
    cout << myqueue.front() << endl;
    cout << myqueue.size() << endl;
    myqueue.dequeue();
    myqueue.dequeue();
    myqueue.dequeue();
    
    try {
        myqueue.dequeue();
    } catch(EmptyQueueException ex) {
        cout << ex.getMessage() << endl;
    }
    cout << (myqueue.isEmpty() ? "true" : "false") << endl;
    return 0;
}
