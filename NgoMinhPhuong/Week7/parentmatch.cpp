#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

bool checkParentMatch(string expr);
int isOpenAndMatchIt(char tmp);

int main (){
	
	
	string a;
	
	cout << "type......:" << endl;
	cin >> a;
	fflush(stdin);
	
	cout << checkParentMatch(a);
		
	return 0;
}

bool 	checkParentMatch(string expr)
{
	
	stack<char> charStack;
	for(int i = 0 ; i < expr.size() ;i++){
		
		if(isOpenAndMatchIt(expr[i])){
			charStack.push(expr[i]);
		}
		else{
			
			if(!charStack.empty()){
				if(isOpenAndMatchIt(charStack.top()) == expr[i]){
					charStack.pop();
				}
			}
			else{
				if(expr[i] == 125 || expr[i] == 41 || expr[i] == 93){
					return 0;
				}
			}
		}
	}
	
	
	return charStack.empty();
		
}

int isOpenAndMatchIt(char tmp){
	
	if(tmp == 123 || tmp == 40 || tmp == 91  ){
		if(tmp == 123){
			return 125;
		}
		else{
			if(tmp == 40){
				return 41;
			}
			else{
				if(tmp == 91){
					return 93;
				}
			}	
		}
	}
	else{
		return 0;
	}
}


