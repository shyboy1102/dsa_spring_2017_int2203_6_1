#include <iostream>
#include <stack>
#include <string>
using namespace std;

//Kiem tra co phai mot cap
bool arePair(char open,char close){
	if(open=='('&&close==')') return true;
	else if(open=='{'&&close=='}') return true;
	else if(open=='['&&close==']') return true;
	return false;
}

bool checkParenMatch(string expr){
	stack<char> S;
	for(int i=0;i<expr.length();i++)
	{
		//Gap ki tu (,[,{ thi push vao stack
		if(expr[i]=='('||expr[i]=='['||expr[i]=='{')
		{
			S.push(expr[i]);	
		}
		//Neu gap ki tu ), ], }
		else if(expr[i]==')'||expr[i]==']'||expr[i]=='}')
		{
			//So sanh ki tu top cua stack(bat dau) voi ki tu ket thuc dau tien(ket thuc) voi ,
			// neu ko pair thi return false
			if(S.empty() ||!arePair(S.top(),expr[i])){
				return false;
			}
			else
			//Neu pair thi loai bo top
			{
				S.pop();
			}
		}
	}
		return S.empty()?true:false;
}
int main(){
	string expr="([[[{{([])}}]]])";
	cout<<(checkParenMatch(expr)?"Match":"Not Match");
}
