#include<bits/stdc++.h>

using namespace std;


class Node{
	
	int data;
	Node* next;
	friend class ListStack;
	
};

class ListStack{
	
	public:
		ListStack();
		int size();
		bool empty();
		const int & top() const;
		void push(int e);
		int pop();
		
		void print();
	
	private:
		Node* S;
		int n;
};

void ListStack::print(){
	
	Node* tmp = this->S;
	
	cout << "(";
	while(tmp->next!=NULL){
		cout << tmp->data << " "; 
		tmp = tmp->next;
	}
	cout << tmp->data << ")" << endl;
}

ListStack::ListStack(){
	
	Node* S = NULL;
	n = 0;
	
}


int ListStack::size(){
	
	return n;
}

bool ListStack::empty(){
	
	return n==0;
}

const int&  ListStack::top() const{

	Node* tmp = this->S;
	while(tmp->next!=NULL){
		tmp = tmp->next;
	}
	
	return tmp->data;
	
}

void ListStack::push(int e){
	if(empty()){
		S->data = e;
		S->next = NULL;
		n++;
	}else{
		
		if(size()==1){
			Node*  newS = new Node();
			newS->data = e;
			newS->next = NULL;
			S->next = newS;
			n++;		
		}
		else{
		
			Node*  newS = new Node();
			newS->data = e;
			newS->next = NULL;
			Node* tmp = this->S;
			
			while(tmp->next!=NULL){
				tmp = tmp->next;
			}
	
			tmp->next = newS;
			n++;	
			
		}
	
	}
	
	 
}

int ListStack::pop(){
	
	if(empty()){
		cout << "error!";
		
	}
	else{
		
		Node* tmp = this->S;
		while(tmp->next->next!=NULL){
			tmp = tmp->next;
		}
		int x = (tmp->next)->data;
		tmp->next = NULL;
		n--;
		return x;	
	}
	
}
int main(){
	
	ListStack test;
	cout <<"push(4) , push(5) , push(6) :" ;
	
	test.push(4);
	test.push(5);
	test.push(6);
	test.print();
	
	cout << "pop() :"; 
	cout <<test.pop()<< endl;
	test.print();
	cout << "top():" << test.top() << endl;
	test.print();
	
	return 0;
}
