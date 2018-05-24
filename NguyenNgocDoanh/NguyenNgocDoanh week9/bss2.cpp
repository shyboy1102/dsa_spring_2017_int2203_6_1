#include<iostream>
#include<fstream>
using namespace std;

#define nullptr NULL

class Node{
	public:
		string data;
		Node * left;
		Node * right;
		Node * parent;
	friend class BstStringSet;
};

class BstStringSet {
	public:
		BstStringSet();
		BstStringSet(char * filename);
		~BstStringSet();
		Node * find(Node * x, const string & k) const;
		void insert(const string & k); // insert key k into the binary search tree T with root = T
		Node * find_min(Node * x) const;
		Node * find_max(Node * x) const;
		Node * next_larger(Node * x) const; // successor
		Node * next_small(Node * x) const; // predecessor
		void inorder_tree_walk(Node * x) const;
		void connect(Node * u, Node * v);
		void del(const string & x);
		Node * getRoot();
	private:
		Node * root;
		Node * find_node(const string & x);
};

Node * BstStringSet::getRoot(){
	return root;
}

Node * BstStringSet::find_node(const string & x){
	Node * temp = root;
	while((temp->data != x) && (temp!=nullptr)){
		if(x < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

BstStringSet::BstStringSet():root(nullptr){

}

BstStringSet::BstStringSet(char * filename){
	string line;
	root = nullptr;
	ifstream file (filename);
	if(file.is_open()){
		while(!file.eof()){
			getline(file,line);
			insert(line);
		}	
	file.close();
	}
	else
		cout << "Khong mo duoc file" << endl;
}

BstStringSet::~BstStringSet(){

}

Node * BstStringSet::find(Node * x, const string & k) const{
	while(x->data!= k && (x!=nullptr)){
		if(k < x->data)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

void BstStringSet::insert(const string & k){
	Node * z = new Node();
	z->data = k;
	z->parent = z->left = z->right = nullptr;
	Node * x = root;
	while(x != nullptr){
		z->parent = x;
		if(k < x->data)
			x = x->left;
		else
			x = x->right;
	}
	if(z->parent == nullptr)
		root = z;
	else if(k < z->parent->data)
		z->parent->left = z;
	else
		z->parent->right = z;
}

Node * BstStringSet::find_min(Node * x) const{
	while(x->left != nullptr)
		x = x->left;
	return x;
}

Node * BstStringSet::find_max(Node * x) const{
	while(x->right != nullptr)
		x = x->right;
	return x;
}

Node * BstStringSet::next_larger(Node * x) const{
	if(x->right != nullptr)
		return find_min(x->right);
	Node * y = x->parent;
	while(y != nullptr && (y->right==x)){
		x = y;
		y = y->parent;
	}
	return y;
}

Node * BstStringSet::next_small(Node * x) const{
	if(x->left != nullptr)
		return find_max(x->left);
	while(x->parent->data > x->data){
		x = x->parent;
	}
	return x->parent;
}

void BstStringSet::connect(Node * u, Node * v) {
	if(u->parent==nullptr)
		root = v;
	else if(u->parent->left == u)
		u->parent->left = v; 
	else
		u->parent->right = v;
	if(v != nullptr)
		u->parent = v->parent;
}

void BstStringSet::del(const string & x) {
	Node * node = find_node(x);
	if(node->left == nullptr)
		connect(node,node->right);
	else if(node->right == nullptr)
		connect(node,node->left);
	else{
		Node * temp = find_min(node->right);
		Node * p = temp->parent;
		connect(temp,temp->right);
		temp->right = node->right;


		connect(node,temp);
		temp->left = node->left;
	}
}

void BstStringSet::inorder_tree_walk(Node * node) const{
	if(node==nullptr)
		return;
	inorder_tree_walk(node->left);
	cout << node->data << " ";
	inorder_tree_walk(node->right);
}


int main(){
	BstStringSet * bss2 = new BstStringSet((char *)"vidu.txt");
	Node * node;
	bss2->inorder_tree_walk(bss2->getRoot());
	cout << "\nfind(tap dong) ->" << (bss2->find(bss2->getRoot(),"tap dong") != nullptr ? "true":"false") << endl;
	node = bss2->find_min(bss2->getRoot());
	cout << "min_tree = " << node->data << endl;
	node = bss2->find_max(bss2->getRoot());
	cout << "max_tree = " << node->data << endl;
	node = bss2->next_small(bss2->find(bss2->getRoot(),"point"));
	cout << "predecessor(point) = " << node->data << endl;
	node = bss2->next_larger(bss2->find(bss2->getRoot(),"cay tknp"));
	cout << "successor(cay tknp) = " << node->data << endl;
	bss2->del("point");
	bss2->inorder_tree_walk(bss2->getRoot());
	return 0;
}