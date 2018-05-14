#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool check_opening_symbol(string s){
	if((s=="(") || (s=="[") || (s=="{"))
		return true;
	return false;
}

bool check_match(string end, string open){
	if((end == ")") && (open == "("))
		return true;
	if((end == "}") && (open == "{"))
		return true;
	if((end == "]") && (open == "["))
		return true;
	return false;
}

bool checkParenMatch(string expr){
	string token[expr.length()];
	int pos = 0;
	while(pos < expr.length()){
		token[pos] = expr.substr(pos, 1);
		pos++;
	}

	stack<string> s;
	for(int i=0;i<expr.length();i++){
		if(check_opening_symbol(token[i]))
			s.push(token[i]);
		else{
			if(s.empty())
				return false;

			if(!check_match(token[i],s.top()))
				return false;
			else
				s.pop();
		}
	}
	if(s.empty())
		return true;
	else
		return false;
}

int main(){
	string expr = "{{}([])((()()))}";
	cout << (checkParenMatch(expr) ? "true" : "false") << endl;
	return 0;
}