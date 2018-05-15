#include<iostream>
#include<fstream>

using namespace std;

class Node {
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
		bool find(const string & x) const;
		void erase(const string & x);
		void insert(const string & x);
		string min() const;
		string max() const;
		string predecessor(const string & x) const;
		string successor(const string & x) const;
		void printInorder() const;
	private:
		Node * root;
        void dest(Node * node);
		Node * findnode(const string & x) const;
		Node * findparent(Node * node) const;
        Node * findnextlarger(Node* node) const;
		Node * findnextsmaller(Node* node) const;
		void del(Node * node);
		void InOrder(Node * node) const;
};

BstStringSet::BstStringSet() {
    root = NULL;
}

BstStringSet::BstStringSet(char * filename) {
    ifstream file(filename);
    string line;
    root = NULL;
    while(getline(file, line))
    {
        insert(line);
    }
    file.close();
}

void BstStringSet::dest(Node * node) {
    if(node) {
        dest(node->left);
        dest(node->right);
        delete node;
    }
}

BstStringSet::~BstStringSet() {
	dest(root);
}

bool BstStringSet::find(const string & x) const {
    Node * temp = root;
	while(temp != NULL) {
		if(temp->data.compare(x) == 0) {
			return true;
        }
		else if(temp->data.compare(x) < 0) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return false;
}

void BstStringSet::insert(const string & x) {
    if(!find(x)) {
        Node * newnode = new Node();
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        Node * v = NULL;
        Node * temp = root;

        while(temp != NULL){
            v = temp;
            if(newnode->data.compare(temp->data) < 0) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }

        if(v == NULL) {
            root = newnode;
        }
        else if(newnode->data.compare(v->data) < 0) {
            v->left = newnode;
        }
        else {
            v->right = newnode;
        }
    }
}

Node * BstStringSet::findnode(const string & x) const {
	if(find(x)) {
        Node * node = root;
        while((node->data.compare(x) != 0) && (node != NULL)) {
            if(node->data.compare(x) > 0) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return node;
	}
	return NULL;
}

Node * BstStringSet::findparent(Node * node) const {
    if(root == node) {
        return NULL;
    }
	Node * temp = root;
	while((temp->left != node) && (temp->right != node)) {
		if(node->data.compare(temp->data) < 0) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return temp;
}

Node* BstStringSet::findnextlarger(Node* node) const {
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

Node* BstStringSet::findnextsmaller(Node* node) const {
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

void BstStringSet::del(Node * node) {
    if((node->right == NULL) && (node->left == NULL)) {
        if(findparent(node)->left == node) {
            findparent(node)->left = NULL;
            return;
        }
        if(findparent(node)->right == node) {
            findparent(node)->right = NULL;
            return;
        }
    }

    if((node->right != NULL) && (node->left == NULL)) {
        node->data = node->right->data;
        node->right = NULL;
        return;
    }

    if((node->right == NULL) && (node->left != NULL)) {
        node->data = node->left->data;
        node->right = NULL;
        return;
    }

    if((node->right != NULL) && (node->left != NULL)) {
        Node* temp = findnextsmaller(node->right);
        node->data = temp->data;
        if(findparent(temp)->left == temp) {
            findparent(temp)->left = NULL;
            return;
        }
        if(findparent(temp)->right == temp) {
            findparent(temp)->right = NULL;
            return;
        }
    }
}

void BstStringSet::erase(const string & x) {
    if(find(x)) {
        Node* temp = findnode(x);
        del(temp);
    }
}

string BstStringSet::min() const {
	Node * temp = root;
	while(temp->left != NULL)
		temp = temp->left;
	return temp->data;
}

string BstStringSet::max() const {
	Node * temp = root;
	while(temp->right != NULL)
		temp = temp->right;
	return temp->data;
}

string BstStringSet::predecessor(const string & x) const {
	if((!find(x)) || x.compare(min()) == 0) {
        return "No Predecessor";
	}

    Node * node = findnode(x);
    if(node->left != NULL) {
        Node * temp = findnextlarger(node->left);
        return temp->data;
    }
    Node * temp = findparent(node);
    while(temp->data.compare(x) > 0){
        temp = findparent(temp);
    }
    return temp->data;
}

string BstStringSet::successor(const string & x) const {
	if((!find(x)) || x.compare(max()) == 0) {
        return "No Successor";
	}

    Node * node = findnode(x);
    if(node->right != NULL) {
        Node * temp = findnextsmaller(node->right);
        return temp->data;
    }
    Node * temp = findparent(node);
    while(temp->data.compare(x) < 0){
        temp = findparent(temp);
    }
    return temp->data;
}


void BstStringSet::InOrder(Node * node) const {
	if(node == NULL) {
		return;
	}
	InOrder(node->left);
	cout << node->data << " ";
	InOrder(node->right);
}

void BstStringSet::printInorder() const {
	InOrder(root);
	cout << endl;
}

int main() {
	BstStringSet bst("vidu.txt");
	bst.printInorder();
	cout << "find('cay tknp') = " << (bst.find("cay tknp") ? "true":"false") << endl;
	cout << "insert('std')" << endl;
	bst.insert("std");
	bst.printInorder();
	cout << "min = " << bst.min() << endl;
	cout << "max = " << bst.max() << endl;
	cout << "predecessor('tap dong') = " << bst.predecessor("tap dong") << endl;
	cout << "successor('std') = " << bst.successor("std") << endl;
	cout << "erase('std')" << endl;
	bst.erase("std");
	bst.printInorder();
	return 0;
}

