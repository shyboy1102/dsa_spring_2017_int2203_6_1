#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool checkParenMatch(string expr){
    stack<char> myStack;
    string open = "{[(";
    string close = "}])";
    char c;
    for(int i = 0; i < expr.length(); i++){
        c = expr.at(i);
        if(open.find_first_of(c,0) != string::npos){
            myStack.push(expr.at(i));
        }
        else{
            if(open.find_first_of(myStack.top(),0) == close.find_first_of(c,0)){
                myStack.pop();
            }
            else return 0;
        }
    }
    if(myStack.empty()) return 1;
    else return 0;
}

int main(){
    string str1 = "{{([])}}";
    string str2 = "{([)]}";
    cout << checkParenMatch(str1) << endl << checkParenMatch(str2);
    return 0;
}





