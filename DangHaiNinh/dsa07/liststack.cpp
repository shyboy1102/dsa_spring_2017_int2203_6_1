#include<iostream>
#include<stdlib.h>
#include<string>
#define nullptr NULL
using namespace std;

class Node
{
	int data;
	Node * next;
	friend class ListStack;
};

class ListStack
{
	public:
		ListStack();
		int size() const;
		bool empty() const;
		const int & top() const;
		void push(int e);
		int pop();
		string decimalToBinary(int n);
		void print();
	private:
		Node * node;
		int n;
		string itoa(int i);
};


ListStack::ListStack():node(nullptr),n(0)
{

}

int ListStack::size() const
{
	return n;
}

bool ListStack::empty() const
{
	return (size() == 0);
}

const int & ListStack::top() const
{
	return node->data;
}

void ListStack::push(int e)
{
	Node * newNode = new Node();
	newNode->data = e;
	newNode->next = NULL;
	if (size() == 0)
	{
		node = newNode;
	}
	else
	{
		newNode->next = node;
		node = newNode;
	}
	n++;
}

int ListStack::pop()
{
	if (empty())
	{

		cout << "\n\tError : Empty ListStack !" << endl;
	}
	else
	{
		Node * newNode = node;
		int temp = newNode->data;
		newNode = newNode->next;
		delete node;
		node = newNode;
		return temp;
	}
}

string ListStack::itoa(int i)
{
	if (i)
	{
		return "1";
	}
	return "0";
}

string ListStack::decimalToBinary(int n)
{
	string st = "";
	while (n)
	{
		push(n%2);
		n /= 2;
	}
	Node * newNode = node;
	while (newNode->next != NULL)
	{
		st += itoa(newNode->data);
		newNode = newNode->next;
	}
	st += itoa(newNode->data);
	return st;
}

void ListStack::print()
{
	cout << "\n\t";
	Node * newNode = node;
	while (newNode->next != NULL)
	{
		cout << newNode->data << " ";
		newNode = newNode->next;
	}
	cout << newNode->data << endl;
}

int main()
{
	ListStack * list = new ListStack();
	for(int i = 0; i < 10; i++)
	{
		list->push(i);
	}
	list->print();
	cout <<"\n\ttop() -> " << list->top() << endl;
	cout <<"\n\tempty() -> " << (list->empty() ? "true" : "false") << endl;
	cout <<"\n\tsize() -> " << list->size() << endl;
	list->pop();
	cout << "\n\tpop() : ";
	cout <<"top() -> " << list->top() << endl;

	ListStack * list2 = new ListStack();
	int i = 100;
	cout << "\n\t" << i << "\n\t(10) = " << list2->decimalToBinary(i) << "(2)" << endl;
	return 0;
}