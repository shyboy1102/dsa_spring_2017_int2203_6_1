#include <iostream>
#include <string>
#include <stack>
using namespace std;

int checkMatch(char o,char c){
    if(o == '[' && c == ']')
        return 1;
    else if(o == '(' && c == ')')
        return 1;
    else if(o == '{' && c == '}')
        return 1;
    return 0;
}
bool checkParenMatch(string expr){
    stack<char> S;
    for(int i=0; i < expr.length(); i++){
        if(expr[i] == '{' || expr[i] == '[' || expr[i] == '(')
            S.push(expr[i]);
        else{
           if(S.empty())
                return false;
            if(checkMatch(S.top(),expr[i]))
                S.pop();
            else
                return false;
        }
      }
    if(S.empty())
        return true;
    else
        return false;
}
int main(){
    stack<string> exp;
    string a = "{}()[()]";

    if(checkParenMatch(a) == 1)
        cout << "Match";
    else
        cout << "Not match";

    return 0;
}
