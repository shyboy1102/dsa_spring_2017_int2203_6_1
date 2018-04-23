#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node{
    string data;
    Node* left ;
    Node* right;
};

class BtsStringSet{
public:
    BtsStringSet(){
        root = NULL;
    }
    ~BtsStringSet(){
        delete root;
    }
    bool find(const string & x){
        Node *p = root;
        while(p != NULL){
            if(x.compare(p->data) == 0){
                return true;
            }
            else{
                if(x.compare(p->data) < 0)  p = p->left;
                else                        p = p->right;
            }
        }
    }
    void insert(const string & x){
        Node * p;
        Node * q;
        q=NULL;p=root;

        while(p != NULL){
    //Kiem tra x da ton tai chua
            q=p;
            if(x.compare(p->data) == 0) break;
            else{
                if(x.compare(p->data) < 0)  p = p->left;
                else                        p = p->right;
            }
        }
    //Insert x
        if(p == NULL){
            Node * newNode = new Node();
            newNode->data = x;
            newNode->left = NULL;
            newNode->right = NULL;
            if(root == NULL)    root = newNode;
            else{
                if(x.compare(q->data) < 0)  q->left = newNode;
                else                        q->right = newNode;
            }
        }
    }
    void erase(const string &x){
        Node *p;
        Node *q;
        Node *child;
        q=NULL;p=root;
    //Kiem tra co ton tai ko
        while(p != NULL){
            if(x.compare(p->data) == 0) break;
            q=p;
            if(x.compare(p->data) < 0)  p = p->left;
            else                        p = p->right;
        }
        if(p == NULL) {
            cout <<"Khong co " << x << endl;
            return;
        }
    //Xoa x
        if(p->left != NULL && p->right != NULL){
            Node *alt = p;
            q=p;
            p = p->left;
            while(p->right != NULL){
                q=p;
                p = p->right;
            }
            alt->data = p->data;
            delete p;
        }
        if(p->left != NULL) child = p->left;
        else                child = p->right;
        if(p == root)       root = child;
        else{
            if(q->left == p)    q->left = child;
            if(q->right == p)   q->right = child;

        }
        delete p;
    }
    string min() const{
        Node *p = root;
        Node *q;
        if(root == NULL)
            return "Empty";
        else{
            while(p != NULL){
                q = p;
                p = p->left;
            }
            return q->data;
        }
    }
    string max() const{
        Node *p = root;
        Node *q;
        if(root == NULL)
            return "Empty";
        else{
            while(p != NULL){
                q = p;
                p = p->right;
            }
            return q->data;
        }
    }
    string predecessor(const string & x) const{
        if(root == NULL)
            return "Empty";
        else{
            Node *p = root;
            string result = "ko co";
            while(p != NULL){
                if(x.compare(p->data) < 0){
                    p = p->left;
                }
                else if (x.compare(p->data) > 0) {
                    result=p->data;
                    p = p->right;
                }
                else{
                    if (p->left != NULL) return p->left->data;
                    if (p->left == NULL) return result;
                }
            }
            return "ko co";
        }
    }
    string successor(const string & x) const{
        if(root == NULL)
            return "Empty";
        else{
            Node *p = root;
            string result="ko co";
            while(p != NULL){
                if(x.compare(p->data) < 0){
                    result = p->data;
                    p = p->left;
                }
                else if(x.compare(p->data) > 0){
                    p = p->right;
                }
                else{
                    if(p->right == NULL)    return result;
                    if(p->right != NULL)  return p->right->data;
                }
            }
            return "khong co";
        }
    }
    BtsStringSet(char* filename):root(NULL){
        ifstream file;
        file.open(filename);
        if(file.is_open()){
            while(!file.eof()){
                string alt;
                file >> alt;
                insert(alt);
            }
        }
    }
    void visit(Node* alt) const{
        if(alt == NULL)
            return;
        cout << alt->data << endl;
        visit(alt->left);
        visit(alt->right);
    }
    void print() const{
        visit(root);
    }

private:
    Node* root;
};

int main(){
    BtsStringSet b("file.txt");
    BtsStringSet a;

    a.insert("l");
    a.insert("f");
    a.insert("cb");
    a.insert("b");
    a.insert("g");
    a.insert("m");
    a.insert("d");
    a.insert("cf");
    a.insert("de");
    a.insert("cc");

    a.erase("g");
    cout << "Min:" << a.min() << endl;
    cout << "Max:" << a.max() << endl;
    cout << "Predecessor:" << a.predecessor("l") << endl;
    cout << "Successor:" << a.successor("cf") << endl;
    if(a.find("a") == 1)
        cout << "Ton tai gia tri can tim" << endl;
    else
        cout << "Khong ton tai gia tri can tim" << endl;
    cout<<"a:" << endl;
    a.print();

}
