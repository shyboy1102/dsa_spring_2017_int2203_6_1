 // Name: Hoang Thi Diep
 // Purpose: Cai dat va test lop hang doi cac so nguyen
 // dung mang vong cap phat dong
 // Note: chuong trinh chua dinh nghia ham enqueue va dequeue
 // -----------------------------------------------------------------------------
 #include <bits/stdc++.h>
 using namespace std;

 #define INIT_CAPACITY 10

 // -----------------------------------------------------------------------------
 // lop ngoai le hang doi rong
 class EmptyQueueException{
 public:
 string getMessage(){ return "Loi: Hang doi rong!";};
 };
 
 class FullQueueException{
 	
 	public:
 		string getMessage(){
 			return "full!" ;
 		}
 };

 // -----------------------------------------------------------------------------
 // lop hang doi cai dat boi mang vong cap phat dong
 // element[r] khong luu du lieu
 // => mang chua duoc toi da (capacity - 1) phan tu
 class ArrayQueue{
 public:
 ArrayQueue();// ham kien tao
 ~ArrayQueue();// ham huy
int size();// ham dem so phan tu trong hang doi
 bool isEmpty();// ham kiem tra hang doi rong
 int front() throw (EmptyQueueException);// ham tra ve gia tri phan tu o dau hang doi
int rear() throw (EmptyQueueException);// ham tra ve gia tri phan tu o cuoi hang doi
 void enqueue(int x) throw (FullQueueException);// ham them x vao cuoi hang doi
 int dequeue() throw (EmptyQueueException);// ham loai phan tu o dau hang doi
 void print();// ham in hang doi
 private:
 bool isFull();// ham kiem tra xem mang day hay chua
 int * element;// con tro toi dau mang
 int capacity;// kich thuoc toi da cua mang
 int f;// chi so cua o dau hang doi
 int r;// chi so cua o lien sau o cuoi hang doi
 };



void ArrayQueue::enqueue(int x) throw (FullQueueException){
	
	if(size() == capacity-1){
		throw FullQueueException();
	}
	else{
		
		this->element[r]= x;
		r = (r+1)%capacity; 
	}
}

int ArrayQueue::dequeue() throw (EmptyQueueException){
	
	if(this->isEmpty()){
		throw EmptyQueueException();
	}
	else{
		int x = element[f];
		f = (f+1)%capacity;
		return x;
	}
}
// ham kien tao
 ArrayQueue::ArrayQueue(){
 capacity = INIT_CAPACITY;
 element = new int[capacity];
 f = 0;
 r = 0;
 }

 // ham huy
 ArrayQueue::~ArrayQueue(){
 delete [] element;
 element = NULL;
 capacity = 0;
 f = 0;
 r = 0;
 }

 // ham dem so phan tu trong hang doi
 int ArrayQueue::size(){
 return (capacity + r - f) % capacity;
 }

 // ham kiem tra hang doi rong
 bool ArrayQueue::isEmpty(){
 return (f == r);
 }
 // ham kiem tra xem mang day hay chua
 bool ArrayQueue::isFull(){
 return (size() == capacity - 1);
 }

// ham tra ve gia tri phan tu o dau hang doi
 int ArrayQueue::front() throw (EmptyQueueException){
 if(isEmpty()) throw EmptyQueueException();
 return element[f];
 }

 // ham tra ve gia tri phan tu o cuoi hang doi
 int ArrayQueue::rear() throw (EmptyQueueException){
 if(isEmpty()) throw EmptyQueueException();
	return element[(capacity + r - 1) % capacity];
 }

// ham in hang doi
 void ArrayQueue::print(){
 cout << "(";
 int s = size();
 for(int i = f, j = 0; j < s - 1; i = (i + 1) % capacity, j++){
cout << element[i] << ", ";
 }
 if(s > 0) cout << rear();
 cout << ")" << endl;
 }

 // -----------------------------------------------------------------------------
 // doan chuong trinh test
 int main(){
 	
 	ArrayQueue queue1;
 	queue1.print();
 	
 	//test 2 chuc nang bo sung
 	
 	cout << "enqueue(5) , enqueue(10) :" ;
 	queue1.enqueue(5);
 	queue1.enqueue(10);
 	queue1.print();
 	cout << "dequeue():";
 	queue1.dequeue();
 	
 	queue1.print();
 	return 0;
 }
 
