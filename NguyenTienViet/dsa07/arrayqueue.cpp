#include<iostream>

using namespace std;

class ArrayQueue{
public:
    ArrayQueue(){
        capacity = 0;
        f = -1;
        r = -1;
        element = new int[0];
    };

    void enQueue(const int x){
        if (capacity == 0){
            capacity = 2;
            int * ar = new int[2];
            ar[0] = x;
            delete[] element;
            element = ar;
            f = 0;
            r = 1;
        }
        else{
            if(size() == capacity - 1){
                    int *ar = new int[2*capacity];

                    for(int i = 0, j = f; i <= size(); i++){
                        ar[i] = element[j];
                        j = (j+1) % capacity;
                    }
                    ar[size()] = x;

                    r = size()+1;
                    f = 0;

                    delete[] element;
                    element = ar;
                    capacity *= 2;
                }
                else{
                    element[r] = x;
                    r = (r + 1) % capacity;
                }
        }
    }

    void deQueue(){
        f = (f + 1) % capacity;
        if (capacity / size() == 4){
            int *ar = new int[capacity/2];

                    for(int i = 0, j = f; i <= size(); i++){
                        ar[i] = element[j];
                        j = (j+1) % capacity;
                    }
                    r = size();
                    f = 0;

                    delete[] element;
                    element = ar;
                    capacity /= 2;
        }
    }

    bool isEmpty() const{
        return (f == r);
    }
    bool isFull() const{
        if (capacity == 0) return true;
        return (size() == capacity - 1);
    }
    size() const{
        if (capacity == 0) return 0;
        return (capacity - f + r) % capacity;
    }
    front() const{
        return element[f];
    }

private:
    int * element;
    int capacity;
    int f, r;

};


int main(){

    ArrayQueue Q;
    Q.enQueue(10);
    Q.enQueue(5);
    Q.enQueue(7);
    Q.deQueue();
    Q.deQueue();
    cout << "Q.front(): " << Q.front() << endl;
    cout << "Q.size() = " << Q.size() << endl;
    cout << "Q.isFull(): " << Q.isFull() << endl;
    return 0;
}
