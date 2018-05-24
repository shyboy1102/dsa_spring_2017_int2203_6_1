#include<iostream>
#include <string.h>
#include <assert.h>
#include <stack>
#include<fstream>
using namespace std;
 
class Node{
	private:
	string data;
	Node* left;
	Node* right;
	Node(const string &x){
		data = x;
		left = NULL;
		right = NULL;
	}
	friend class BstStringSet;
};


class BstStringSet{
	public:
		BstStringSet(){
			root = NULL;
		}
		
		BstStringSet(char* filename){
			ifstream file(filename);
    		string line;
		    root = NULL;
		    while(getline(file, line))
		    {
		        insert(line);
		    }
		    file.close();

		}
		
		~BstStringSet(){
			MakeEmpty(root);
		}
		
		bool find(const string& x){
			return find(x, root);
		}
		
		void erase(const string & x){
			erase(x,root);
		}
		
		void insert(const string&x ){
			insert(x,root);
		}
		
		string Min() const{
			return Min(root);
		}
		
		string Max() const{
			return Max(root);
		}
		
		string predecessor(const string& x) const{
			return predecessor(x, root);
		}
		
		string successor(const string& x) const{
			return successor(x,root);
		}
		void printInorder() const{
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
			 
			bool find(const string& x,Node* &P) const{
				if(P!=NULL){
					if(x==P->data)
						return true;
					else if(x<P->data)
							return find(x,P->left);
						else 
							return find(x,P->right);
				}
				else
					return false;
			}
		
			void erase(const string& x, Node* &P){
				if(P!=NULL){
					if(x<P->data)
						erase(x,P->left);
					else if(x>P->data)
						erase(x,P->right);
					else if((P->left!=NULL) && (P->right!=NULL)){
						P->data = eraseMin(P->right);
					}
						else{
							Node* Ptr = P;
							P = (P->left!=NULL)? P->left:P->right;
							delete Ptr;
						}
				}
			}
			string eraseMin(Node* &P){
				assert(P!=NULL);
				if(P->left!=NULL)
					return eraseMin(P->left);
				else{
					string element = P->data;
					Node* Ptr = P;
					P = P->right;
					delete Ptr;
					return element;
				}
			}
		
			void insert(const string &x,Node* &P){
				if(P==NULL){
				P = new Node(x);
			}
			else if(x<P->data)
					insert(x,P->left);
			else if(x>P->data)
					insert(x,P->right);
			}
			
			string Min(Node* P) const{
				assert(P!=NULL);
				if(P->left!=NULL)
					return Min(P->left);
				else
					return P->data;
			}	 
			
			string Max(Node* P) const{
				assert(P!=NULL);
				if(P->right!=NULL)
					return Max(P->right);
				else
					return P->data;
			}
			
			string predecessor(const string&x, Node* P) const{
				stack<Node*> S;
				stack<string> str;
				while(P!=NULL){
					S.push(P);
					P = P->left;
				}
				while(!S.empty()){
					P = S.top();
					str.push(P->data);
					S.pop();
					P = P->right;
					while(P!=NULL){
						S.push(P);
						P = P->left;
					}
				}
				while(!str.empty()){
					string t = str.top();
					str.pop();
					if(x==t){
						return str.top();
					}	
				}
			}
			
			string successor(const string&x, Node* P) const{
				stack<Node*> S;
				stack<string> str;
				while(P!=NULL){
					S.push(P);
					P = P->left;
				}
				while(!S.empty()){
					P = S.top();
					str.push(P->data);
					S.pop();
					P = P->right;
					while(P!=NULL){
						S.push(P);
						P = P->left;
					}
				}
				while(!str.empty()){
					string t = str.top();
					str.pop();
					if(x==str.top())
						return t;
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
main(){
	
	BstStringSet bst1;
	bst1.insert("ab");
	bst1.insert("cd");
	bst1.insert("gh");
	bst1.insert("tr");
	bst1.insert("aa");
	bst1.insert("ga");
	bst1.insert("gb");
	bst1.insert("cc");
	if(bst1.find("bc"))
		cout<<"true!"<<endl;
	else
		cout<<"false!"<<endl;
		
	cout<<"min:"<<bst1.Min()<<endl;
	cout<<"max:"<<bst1.Max()<<endl;
	bst1.printInorder();
	cout<<"successor(ab):"<<bst1.successor("ab")<<endl;
	cout<<"predexessor(ab):"<<bst1.predecessor("ab")<<endl;
	bst1.erase("cd");
	cout<<"Cay khi xoa:"<<endl;
	bst1.printInorder();
	
	BstStringSet bst2("ctknp.txt");
	bst2.printInorder();	
}
