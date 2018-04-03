#include <iostream>
#include <stack>

using namespace std;

bool checkParenMatch(string expr) {
    stack<int> ParentPos;

    for(int i = 0; i < expr.length(); i++) {
        if(expr[i] == '(') {
            ParentPos.push(1);
        }
        else if(expr[i] == '[') {
            ParentPos.push(2);
        }
        else if(expr[i] == '{') {
            ParentPos.push(3);
        }
        else if(expr[i] == ')') {
            if(!ParentPos.empty() && ParentPos.top() == 1) {
                ParentPos.pop();
            }
        }
        else if(expr[i] == ']') {
            if (!ParentPos.empty() && ParentPos.top() == 2) {
                ParentPos.pop();
            }
        }
        else if(expr[i] == '}') {
            if (!ParentPos.empty() && ParentPos.top() == 3) {
                ParentPos.pop();
            }
        }
        else {
            ParentPos.push(4);
        }
    }
    return ParentPos.empty();
}
int main() {
    string strExpr;
    cout << "Enter parentness string: ";
    getline(cin, strExpr);
    cout << (checkParenMatch(strExpr)? "True" : "False") << endl;
    return 0;
}
