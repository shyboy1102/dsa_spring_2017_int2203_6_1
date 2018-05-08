#include<iostream>
#include<fstream>
using namespace std;

#define nullptr NULL

class Node{
	private:
		string data;
		Node * left;
		Node * right;
	friend class BstStringSet;
};

class BstStringSet {
	public:
		BstStringSet();
		BstStringSet(char * filename);
		~BstStringSet();
		bool find(const string & x) const;
		void erase(const string & x);
		void insert(const string & x);
		string min() const;
		string max() const;
		string predecessor(const string & x) const; // xau dung lien truoc trong tap dong theo thu tu tu dien
		string successor(const string & x) const; // xau dung lien sau x trong tap dong theo thu tu tu dien
		void printInorder() const;  // postOrder
		void clear(Node * node);
	private:
		Node * root;
		bool find_with_node(const string & x, Node * temp) const; // find key x from node temp
		Node * find_node(const string & x, Node * node) const; // find node have key x from node node
		Node * find_parent_node(Node * node) const; // find parent of node node
		void InOrder(Node * node) const;
		string min_subtree(Node * x) const; // find min from a node x
		string max_subtree(Node * x) const; // find max from a node x
		void Trans_Plant(Node * u, Node * v);
};

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

void BstStringSet::clear(Node * node){
	if(node == nullptr)
		return;
	node = nullptr;
	clear(node->left);
	clear(node->right);
}


BstStringSet::~BstStringSet(){
	clear(root);
}


bool BstStringSet::find_with_node(const string &x, Node * temp) const{
	while(temp != nullptr){
		if(x==temp->data)
			return true;
		else if(x < temp->data)
			return find_with_node(x,temp->left);
		else
			return find_with_node(x,temp->right);
	}
	return false;
}

bool BstStringSet::find(const string & x) const{
	return find_with_node(x, root);
}

Node * BstStringSet::find_node(const string & x, Node * node) const{
	if(find(x)){
		if(x==node->data)
			return node;
		else if(x < node->data)
			return find_node(x, node->left);
		else
			return find_node(x, node->right);
	}
	return nullptr;
}

Node * BstStringSet::find_parent_node(Node * node) const {
	Node * temp = root;
	if(root==node) return nullptr;
	while((temp->left != node) && (temp->right != node)){
		if(node->data < temp->data)
			temp = temp->left;
		else{
			temp = temp->right;
		}
	}
	return temp;
}

void BstStringSet::insert(const string & x){
	Node * z = new Node(); // create a new node
	z->data = x;
	z->left = nullptr;
	z->right = nullptr;

	Node * y = nullptr;
	Node * x_ = root;
	while(x_ != nullptr){
		y = x_;
		if(z->data < x_->data){
			x_ = x_->left;
		}
		else x_ = x_->right;
	}
	if(y==nullptr){
		root = z;
	}
	else if(z->data < y->data){
		y->left = z;
	}
	else y->right = z;
}

void BstStringSet::Trans_Plant(Node * u, Node * v){
	Node * temp = find_parent_node(u);
	if(temp==nullptr)
		root = v;
	else if(u == temp->left)
		temp->left = v;
	else 
		temp->right = v;
	if(v!=nullptr){
		Node * temp1 = find_parent_node(v);
		temp1 = temp;
	}
}

void BstStringSet::erase(const string & x){
	Node * node = find_node(x, root);
	if(node == nullptr)
		cout << "Khong tim duoc node trong BstStringSet" << endl;
	else{
		if(node->left == nullptr)
			Trans_Plant(node,node->right);
		else if(node->right== nullptr)
			Trans_Plant(node,node->left);
		else{
			Node * y = find_node(min_subtree(node->right),root);
			Node * temp = find_parent_node(y);
			//if(temp != node)
			{
				Trans_Plant(y,y->right);
				y->right = node->right;
			}
			Trans_Plant(node,y);
			y->left = node->left;
		}
	}
}

string BstStringSet::min() const{
	Node * temp = root;
	while(temp->left != nullptr)
		temp = temp->left;
	return temp->data;
}

string BstStringSet::max() const{
	Node * temp = root;
	while(temp->right != nullptr)
		temp = temp->right;
	return temp->data;
}

string BstStringSet::min_subtree(Node * x) const{
	while(x->left != nullptr)
		x = x->left;
	return x->data;
}

string BstStringSet::max_subtree(Node * x) const{
	while(x->right != nullptr)
		x = x->right;
	return x->data;
}

string BstStringSet::predecessor(const string & x) const{
	if((!find(x)) ||x.compare(min())==0) return "No Successor";

	Node * node = find_node(x,root);
	if(node->left != nullptr)
		return max_subtree(node->left);
	Node * temp = find_parent_node(node);
	while(temp->data > x){
		temp = find_parent_node(temp);
	}
	return temp->data;
}

string BstStringSet::successor(const string & x) const {
	if((!find(x)) || x.compare(max())==0) return "No Successor";
	
	Node * node = find_node(x, root);	
	if(node->right != nullptr)
		return min_subtree(node->right);
	
	Node * temp = find_parent_node(node);
	while(temp->data < x){
		temp = find_parent_node(temp);
	}
	return temp->data;      
}


void BstStringSet::InOrder(Node * node) const{
	if(node==nullptr)
		return;
	InOrder(node->left);
	cout << node->data << " ";
	InOrder(node->right);
}

void BstStringSet::printInorder() const{
	InOrder(root);
}

int main(){
	BstStringSet * bss1 = new BstStringSet((char *)"vidu.txt");
	bss1->printInorder();
	cout << "\nfind(tap dong) ->" << (bss1->find("tap dong") ? "true":"false") << endl;
	cout << "min_tree = " << bss1->min() << endl;
	cout << "max_tree = " << bss1->max() << endl;
	cout << "predecessor(point) = " << bss1->predecessor("point") << endl;
	cout << "successor(cay tknp) = " << bss1->successor("cay tknp") << endl;
	bss1->erase("giai thuat");
	cout << "erase(giai thuat) -> ";
	bss1->printInorder();
	return 0;
}

