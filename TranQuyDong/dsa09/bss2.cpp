#include<iostream>
#include <string.h>
#include <assert.h>
#include<fstream>
using namespace std;

class Node{
	string data;
	Node* left;
	Node* right;
	Node* parent;
	Node(const string &x)
	{
		data = x;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	friend class BstStringSet;
};

class BstStringSet{
	public:
		BstStringSet()
		{
			root = NULL;
		}
		
		BstStringSet(char* filename)
		{
			ifstream file(filename);
    		string line;
		    root = NULL;
		    while(getline(file, line))
		    {
		        insert(line);
		    }
		    file.close();

		}
		
		~BstStringSet()
		{
			MakeEmpty(root);
		}
		
		bool find(const string & x)
		{
			return find(x,root);
		}
		
		void erase(const string & x)
		{
			erase(x,root);
		}
		
		void insert(const string & x)
		{
			insert(x,root);	
			
		}
		
		string Min() const
		{
			return Min(root);
		}
		
		string Max() const
		{
			return Max(root);
		}
		
		string predecessor(const string & x) const
		{
			return predecessor(x,root);
		}
		
		string successor(const string & x) const
		{
			return successor(x,root);
		}
		
		void printInorder() const
		{
			printInorder(root);
		}
		
		
	private:
		Node* root;
		
		void MakeEmpty(Node* &P){
			if(P!=NULL){
				MakeEmpty(P->left);
				MakeEmpty(P->right);
				delete P;
				P = NULL;
			}
		}
		bool find(const string & x, Node* P)
		{
			if(P==NULL)
				return false;
			while(P!=NULL)
			{
				if(x==P->data)
					return true;
				else if(x<P->data)
					P = P->left;
				else
					P = P->right;
			}
		}
		
		void erase(const string & x, Node* &N)
		{
			Node* P = N;
			while(P!=NULL && x!=P->data){
				if(x<P->data)
					P = P->left;
				else
					P = P->right;
			}
			if(P->left==NULL && P->right==NULL){
				if(P->parent->left == P)
					P->parent->left = NULL;
				else if(P->parent->right == P)
					P->parent->right = NULL;
				delete P;
				P = NULL;
			}
			else if(P->left==NULL){
					P->right->parent = P->parent;
					if(P->parent->left == P){
						P->parent->left = P->right;
					}
					else if(P->parent->right == P){
						P->parent->right = P->right;
					}
					delete P;
					P = NULL;
			}
			else if(P->right == NULL){
				P->left->parent = P->parent;
				if(P->parent->left == P){
					P->parent->left = P->left;
				}
				else if(P->parent->right == P){
					P->parent->right = P->left;
				}
				delete P;
				P = NULL;	
			}
			else{
				string str = successor(P->data,N);
				Node* Ptr = P;
				//cout<<P->data<<endl;
				while(Ptr!=NULL && str!=Ptr->data){
					if(str < Ptr->data)
						Ptr = Ptr->left;
					else
						Ptr = Ptr->right;
				}
				if(Ptr->right == NULL)
					Ptr->parent->right = NULL;
				else
					Ptr->parent->right = Ptr->right;
				if(Ptr->parent->left == Ptr){
					Ptr->parent->left = Ptr->right;
				}
				else if(Ptr->parent->right == Ptr){
					Ptr->parent->right = Ptr->right;
				}
				Node* temp = Ptr;
				P->data = str;
				delete temp;
			}
		}
		
		void insert(const string & x, Node* &P)
		{
			Node* Ptr = new Node(x);
			Node* temp = P;
			while(temp!=NULL)
			{
				Ptr->parent = temp;
				if(x<temp->data)
					temp= temp->left;
				else if(x>temp->data)
					temp = temp->right;
			}
			Node* temp2 = Ptr->parent;
			if(temp2 == NULL)
				P = Ptr;
			else if(x<temp2->data)
				temp2->left = Ptr;
			else 
				temp2->right = Ptr;
		}
		
		string Min(Node* P) const
		{
			assert(P!=NULL);
			while(P->left!=NULL){
				P = P->left;
			}
			return P->data;
		}
		
		string Max(Node* P) const
		{
			assert(P!=NULL);
			while(P->right!=NULL){
				P = P->right;
			}
			return P->data;
		}
		
		string predecessor(const string & x, Node* P) const
		{
			assert(x!=Min(P));
			while(P!=NULL && x!=P->data){
				if(x<P->data)
					P = P->left;
				else
					P = P->right;
			}
			if(P->left!=NULL)
				return P->left->data;
			else{
				Node* Ptr = P->parent;
				while(Ptr!=NULL && P==Ptr->left){
					P = Ptr;
					Ptr = Ptr->parent;
				}
				return Ptr->data;
			}
		}
		
		string successor(const string &x, Node* P) const
		{
			assert(x!=Max(P));
			while(P!=NULL && x!=P->data){
				if(x<P->data)
					P = P->left;
				else
					P = P->right;
			}
			if(P->right!=NULL)
				return Min(P->right);
			else{
				Node* Ptr = P->parent;
				while(Ptr!=NULL && P==Ptr->right){
					P = Ptr;
					Ptr = Ptr->right;
				}
				return Ptr->data;
			}
		}
		
		void printInorder(Node* P) const{
				if(P->left!=NULL)
					printInorder(P->left);
				cout<<P->data<<endl;
				if(P->right!=NULL)
					printInorder(P->right);
				}
};

int main(){
	BstStringSet bst1;
	bst1.insert("ab");
	bst1.insert("cd");
	bst1.insert("gh");
	bst1.insert("tr");
	bst1.insert("aa");
	bst1.insert("ga");
	bst1.insert("gb");
	bst1.insert("cc");
	if(bst1.find("ab"))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	
	cout<<"min:"<<bst1.Min()<<endl;
	cout<<"max:"<<bst1.Max()<<endl;
	bst1.printInorder();
	cout<<"successor(ab):"<<bst1.successor("ab")<<endl;
	cout<<"predecessor(ab):"<<bst1.predecessor("ab")<<endl;
	bst1.erase("cd");
	cout<<"Cay khi xoa:"<<endl;
	bst1.printInorder();
	
	BstStringSet bst2("ctknp.txt");
	bst2.printInorder();
	return 0;
}
