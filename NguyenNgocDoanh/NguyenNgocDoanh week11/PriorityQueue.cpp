#include<iostream>
#include<math.h>

using namespace std;

#define nullptr NULL

class Node{
	private:
		int key;
		char data;
		Node * left;
		Node * right;
		Node * parent;
		int depth;
		int count;

	public:
		Node(const int & key,const char & data):key(key),data(data){
			left = nullptr;
			right = nullptr;
			parent = nullptr;
			depth = 0;
			count = 0;
		}
	friend class PriorityQueue;
};

class PriorityQueue {
	public:
		PriorityQueue();
		~PriorityQueue();
		Node * findMin();
		void insert(int key, char data);
		void removeMin();
		void print();
	private:
		Node * root;
		void insert_a_node(Node * x, Node * y);
		void print_heap(Node * node);
		Node * find_node(Node * node, int k, int d, int c); // key depth count
};

PriorityQueue::PriorityQueue():root(nullptr){}

PriorityQueue::~PriorityQueue(){

}

Node * PriorityQueue::find_node(Node * node, int k, int d, int c){
	if(node->key == k && node->depth == d && node->count == c)
		return node;
	while(node != nullptr){
		find_node(node->left,k,d,c);
		find_node(node->right,k,d,c);
	}
	return nullptr;
}

void PriorityQueue::insert(int key, char data){
	Node * p = new Node(key, data);
	if(root == nullptr){
		root = p;
		depth++;
	}

}
/*
// insert node y to node x
void PriorityQueue::insert_a_node(Node * x, Node * y){
	
	if(x == nullptr)
		root = y;
	else if(x->left == nullptr)
		x->left = y;
	else
		x->right = y;
	y->parent = x;
}

void PriorityQueue::insert(int key, char data){
	Node * temp = root;
	Node * node = new Node(key,data);
	
	while(count <= pow(2,depth)){
		if(count < pow(2,depth)/2) insert_a_node(temp, node);
		count++;
	}
	depth++;
}
*/

void PriorityQueue::print_heap(Node * node){
	if(node == nullptr)
		return;
	cout << node->key << " ";
	print_heap(node->left);
	print_heap(node->right);
}

void PriorityQueue::print(){
	print_heap(root);
}

int main(){
	PriorityQueue * p = new PriorityQueue();
	p->insert(2,'A');
	p->insert(3,'B');
	p->insert(4,'C');
	p->insert(5,'E');
	p->print();
	return 0;
}