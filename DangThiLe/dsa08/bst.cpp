#include <iostream>
#include <string>
using namespace std;

struct Node{
	string data;
	Node * left;
	Node * right;
	Node * parent;
};
class BstStringSet{
public:
	//Ham kien tao khong tham so
	BstStringSet(){
		this->root = NULL;
	}
	// Kien tao tu file
	BstStringSet(char* filename){
		this->root = NULL;
		ifstream myfile;
		myfile.open(filename);
		if(myfile.is_open()){
			while(!myfile.eof()){
				string tmp;
				myfile >> tmp;
				this->insert(tmp);
			}
		}
	}
	// Ham huy
	~BstStringSet(){
		delete this->root;
	}
	//Kiem tra xau x co trong tap khong
	bool find(const string &x){
		Node* tmp = root;
		while(tmp != NULL){
			if(tmp->data.compare(x) == 0)
				return true;
			if(x.compare(tmp->data) < 0)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		return false;
	}
	//Xoa x
	void erase(const string &x){
		Node *tmp =root;
		while(tmp != NULL){
			if(tmp->data.compare(x) == 0)
				earse(x);
			if(x.compare(tmp->data) < 0)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
	}
	// Chen x
	void insert(const string &x){
		Node* tempNode = new Node();
		tempNode->data = x;
		tempNode->left = NULL;
		tempNode->right = NULL:
		tempNode->parent = NULL;
	}
	// Tra ve xau dung dau theo thu tu tu dien 
	string min() const {
	
	}
	// Tra ve xau dung cuoi theo thu tu tu dien
	string max() const {
	
	}
	// Tra ve xau dung lien truoc x theo thu tu tu dien
	string predecessor(const string &x) const {
		
	}
	// Tra ve xau dung lien sau x theo thu tu tu dien
	string successor(const string &x) const {
	
	}
	// Duyet cay theo thu tu trong
	void printInorder() const {
		
	}
private:
	Node * root;
};

int main(){
	
	return 0;
}
