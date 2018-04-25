#include<iostream>
#include<stdlib.h>
#include<string>
#define nullptr NULL
using namespace std;

class Node {
	int data;
	Node * next;
	friend class ListStack;
};

class ListStack{
	public:
		ListStack(); //Kien tao ngan xep rong
		int size() const;
		bool empty() const;
		const int & top() const;
		void push(int e);  // them phan tu vao dinh stack
		int pop(); // xoa phan tu o dau stack
		string decimalToBinary(int n);
		void print();
	private:
		Node * node;
		int n;
		string itoa(int i); // ham tra ve kieu string cua so nguyen i
};


ListStack::ListStack():node(nullptr),n(0) {

}

int ListStack::size() const{
	return n;
}

bool ListStack::empty() const{
	return (size()==0);
}

const int & ListStack::top() const {
	return node->data;
}

void ListStack::push(int e){
	Node * q = new Node();
	q->data = e;
	q->next = NULL;
	if(size()==0)
		node = q;
	else {
		q->next = node;
		node = q;
	}
	n++;
}

int ListStack::pop(){
	if(empty())
		cout << "Error : Empty ListStack !" << endl;
	else {
		Node * q = node;
		int temp = q->data;
		q = q->next;
		delete node;
		node = q;
		return temp;
	}
}

string ListStack::itoa(int i){
	if(i)
		return "1";
	return "0";
}

string ListStack::decimalToBinary(int n){
	string st = "";
	while(n){
		push(n%2);
		n /= 2;
	}
	Node * q = node;
	while(q->next != NULL){
		st += itoa(q->data);
		q = q->next;
	}
	st += itoa(q->data);
	return st;
}

void ListStack::print(){
	Node * q = node;
	while (q->next != NULL){
		cout << q->data << " ";
		q = q->next;
	}
	cout << q->data << endl;
}

int main(){
	ListStack * ls = new ListStack();
	for(int i=0;i<10;i++)
		ls->push(i);
	ls->print();
	cout <<"top() -> " << ls->top() << endl;
	cout <<"empty() -> " << (ls->empty() ? "true" : "false") << endl;
	cout <<"size() -> " << ls->size() << endl;
	ls->pop();
	cout << "pop() : ";
	cout <<"top() -> " << ls->top() << endl;

	ListStack * ls1 = new ListStack();
	int i = 100;
	cout << i << "(10) = " << ls1->decimalToBinary(i) << "(2)" << endl;
	return 0;
}


// to_string
// lexical_cast<string>(a);