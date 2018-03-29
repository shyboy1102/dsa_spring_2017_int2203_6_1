#include <iostream>
#include <string>
#include <stack>

using namespace std;
//template <typename T>

//struct node {
//	char c;
// 	node* next;
// 	node(){
//  		next = nullptr;
// 	}
//};
//class stack {
// private:
//	     node* head;
// public:
//	     stack()
//			: head(nullptr)
//		 {}
//
//	bool is_empty()
//		 {
//		  if(!this->head)
//		    return true;
//		  else
//		    return false;
//		 }
//		 
//		 void push(char c)
//		 {
//                  node* p = new node;
//                  p->c = c;
//	      if(this->is_empty())
//	       this->head = p;
//	      else
//	      {
//	       p->next = this->head;
//	       this->head = p;
//              }
//		 }
//
//		 char pop()
//		 {
//		  if(this->is_empty())
//           return '\a';
//          else
//          {
//           node* tmp = this->head;
//           this->head = this->head->next;
//		   char c = tmp->c;
//		   delete tmp;
//		   return c;
//          }
//		 }
//};

bool checkParenMatch(string& expr) {
	stack<char> list;
	for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            list.push(expr[i]);
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            char c = list.pop();
            if(c == '\a')
        }
    }
}
int main(){
	string expr;
	getline(std::cin, expr);
	if(checkParenMatch(expr))
		cout << "correct" <<endl;
	else 
		cout << "false";
	return 0;
}
