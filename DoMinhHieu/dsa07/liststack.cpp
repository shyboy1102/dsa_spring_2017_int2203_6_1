#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;
class Node{
	int data;
	Node * next;
	friend class ListStack;
};
class ListStack{
	public:
		ListStack(){
			S=NULL;
		};
		Node *MakeNode(int x){
			Node *P=new Node();
			P->next=NULL;
			P->data=x;
			return P;
		}
		int size() const{
			return n;
		};
		bool empty() const{
			return S==NULL;
		};
		const int & top() const{
			return S->data;
		};
		void push(int e){
			Node *P=MakeNode(e);
			P->next=S;
			S=P;
		};
		string makeString(){
			std::stringstream ss;
			string s="";
			while(!empty())
			{
				int x=top();
				pop();
				//cout<<x;
				ss<<s<<x;
			}
			return ss.str();
		}
		int pop(){
			if(!empty()){
				int x=S->data;
				S=S->next;
				return x;
			}
		};
	private:
		Node *S;
		int n;
};

string decimalToBinary(int n){
	
	ListStack l;
	
	while((n-n%2)>=1||n==1)
	{
		l.push(n%2);		
		n=floor(n/2);		
	}
	return l.makeString();
	
}
int main(){
	cout<<decimalToBinary(11);
	return 0;
}

