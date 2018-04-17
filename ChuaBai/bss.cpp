#include<bits/stdc++.h>

using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
    Node* parent;
} ;

class BstStringSet{
public:
    BstStringSet();
    ~BstStringSet();
    BstStringSet(char* filename);
    void insert(const string& x);
    bool find(const string& x) const;
    void erase(const string& x);
    void erase(Node* tmp);
    Node* leftMost(Node* tmp);
    void printInorder() const;
    void visit(Node* tmp)const;


private:
    Node* root;

};

void BstStringSet::visit(Node* tmp) const{
    if(tmp==NULL)
        return;

    cout << tmp->data<<endl;
    visit(tmp->left);
    visit(tmp->right);
}
void BstStringSet::printInorder()const{

    visit(root);

}

BstStringSet::BstStringSet(){
    this->root = NULL;
}

BstStringSet::~BstStringSet(){
    delete this->root;
}

Node* BstStringSet::leftMost(Node* tmp){
    while(tmp->left!=NULL){
        tmp = tmp->left;
    }
    return tmp;
}

void BstStringSet::erase(const string& x){
    Node* tmp = root;
    while(tmp!=NULL){
        if(tmp->data.compare(x)==0){
            erase(tmp);
        }
        if(x.compare(tmp->data) < 0){
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }
}

void BstStringSet::erase(Node* tmp){
    if(tmp->right == NULL && tmp->left == NULL){
        if(tmp->parent==NULL){
                root = NULL;
                return;
        }
        if(tmp->parent->left==tmp){
            tmp->parent->left = NULL;
            delete tmp;
        }
        else{
            tmp->parent->right = NULL;
            delete tmp;
        }
        return;
    }

    if(tmp->right!=NULL&&tmp->right!=NULL){
        Node* tmp2 = leftMost(tmp->right);
        tmp->data = tmp2->data;
        if(tmp2->parent->left == tmp2){
            tmp2->parent->left = NULL;
            delete tmp2;
        }else{
            tmp2->parent->right = NULL;
            delete tmp2;
        }
        return;
    }

    if(tmp->right!=NULL){
        tmp = tmp->right;
        return;
    }
    else{
        tmp = tmp->left;
        return;
    }



}

bool BstStringSet::find(const string & x) const{
    Node* tmp = root;
    while(tmp!=NULL){
        if(tmp->data.compare(x)==0){
            return true;
        }
        if(x.compare(tmp->data) < 0){
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }
    return false;
}

BstStringSet::BstStringSet(char* filename){

    this->root = NULL;

    ifstream myfile ;
    myfile.open(filename);

    if(myfile.is_open()){
        while(!myfile.eof()){
            string tmp;
            myfile >> tmp;
            this->insert(tmp);
        }
    }
}

void BstStringSet::insert(const string& x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left  = NULL;
    newNode->right  = NULL;
    newNode->parent = NULL;
    Node* tmp = root;
    if(tmp == NULL){
            this->root = newNode;
            return;
    }

    while(tmp!=NULL){

        if(x.compare(tmp->data) < 0){
            if(tmp->left!=NULL){
                tmp = tmp->left;
            } else{
                tmp->left = newNode;
                newNode->parent = tmp;
                return;
            }
        }
        else {
            if(tmp->right!=NULL){
                tmp = tmp->right;
            } else{
                tmp->right = newNode;
                newNode->parent = tmp;
                return;
            }
        }


    }
}

int main(){
    BstStringSet a = BstStringSet("test.txt");
    a.printInorder();
    cout <<a.find("f");
    a.erase("a");
    a.printInorder();
}



