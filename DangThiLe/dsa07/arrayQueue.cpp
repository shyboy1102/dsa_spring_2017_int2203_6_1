
#include <iostream>

using namespace std;


class ArrayQueue {
public:
    // constructor
    ArrayQueue(int n) {
		capacity = n;
		array = new int[capacity];
		
		first = -1;
		last = -1;
		size = 0;
    }

    // destructor
    ~ArrayQueue( ) {
    	delete [] array;
    }
    bool empty() const {
		return (size == 0);
	}
	void enqueue(int const& value){
		if(size == capacity)
			cout << "Hang doi day!\n";
		else {
			last++;
			array[last] = value;
			size++;
		}
	}
	int dequeue(){
		if(empty())
			cout << "Hang doi rong!\n";
		else{
			int temp = array[first];
			size--;
			first++;
			return temp;
		}	
	}
	void print(){
		for(int i = 0; i< size; i++)
			cout << array[i] << endl;
		if(empty())
			cout << "Hang doi rong!\n";	
}
private:
	int* array;
    int capacity, size;
    int first, last;

};

int main(){
	ArrayQueue q(3);
	
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	
	q.print();
	
	q.enqueue(400);

	q.dequeue();
	q.dequeue();
	
	q.print();
	
	q.dequeue();
	
	q.print();



}
