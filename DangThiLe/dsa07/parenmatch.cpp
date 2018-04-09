#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkParenMatch(string& expr) {
	stack<char> list;
	
	for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            list.push(expr[i]);
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
        	if (list.empty())
        		return false;
			else {
				char c = list.top();
            	if(c == '(' && expr[i] == ')' ||
				   c == '[' && expr[i] == ']' ||
	   		       c == '{' && expr[i] == '}' ) {
            		list.pop();
//            		return true;
				}
			}   	
        }
    }
    if(list.empty())
    	return true;
    else 
		return false;
}
int main(){
	string expr;
	getline(std::cin, expr);
	
	if(checkParenMatch(expr))
		cout << "correct" <<endl;
	else 
		cout << "incorrect";
	return 0;
}
