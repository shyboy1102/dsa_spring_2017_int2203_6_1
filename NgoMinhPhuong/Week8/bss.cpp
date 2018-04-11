
#include<bits/stdc++.h>

using namespace std;


struct Node{

    string data;
    Node* left;
    Node* right;

    Node(const string tmp){
        this->data = tmp;
        this->left = NULL;
        this->right = NULL;
    }


};




class BstStringSet {
public:
    BstStringSet();
    ~BstStringSet();
    BstStringSet(char * fileName);
    bool find(const string & x );
    void erase (const string & x);
    void insert (const string & x);
    string min() const;
    string max () const;
    string predeeessor (const string & x) const ;
    string successor (const string & x) const ;
    void printInorder()const;
    void inOrder(Node* tmp) const;
    Node* deleteNode(Node* root ,Node* left , Node* right);


private:
    Node* root;

};

Node* BstStringSet::deleteNode(Node* root , Node* left ,Node* right){


    if(root!=NULL){
        return root;
    }
    else {
        if(right==NULL){
             root = deleteNode(left , left->left,left->right);
        }
        else if(left==NULL){
            root = deleteNode(left , right->left,right->right);
        }
        else if(right==NULL&&left==NULL){

                Node* tmp = root;
                root = NULL;
                return tmp;
        }
    }



}

void BstStringSet::inOrder(Node* tmp)const{


    if(tmp!=NULL){
        if(tmp->left!=NULL){
            inOrder(tmp->left);
            cout << tmp->data << endl;
            if(tmp->right!=NULL){
                inOrder(tmp->right);
            }
        }
        else{
            cout << tmp->data << endl;
            if(tmp->right!=NULL){
                inOrder(tmp->right);
            }
        }
    }

}

BstStringSet::BstStringSet(){

    this->root = NULL;
}

BstStringSet::BstStringSet(char* fileName){

    ifstream readFile;

    root = NULL;

    readFile.open(fileName);

    if(readFile.is_open()){

        while(!readFile.eof()){

                string tmp2;
                readFile >> tmp2;
                insert(tmp2);

        }

        readFile.close();

    }





}



void BstStringSet::erase(const string & x){

    if(find(x)){


            Node* tmp = root;

            bool isDone = false;

            if(tmp==NULL){


                return;
            }

        while(!isDone){


            if(tmp!=NULL){

                if(tmp->data.compare(x)==0){

                    tmp = NULL;
                    tmp = deleteNode(tmp , tmp->left , tmp->right);
                    return;

                }
                else if(tmp->data.compare(x)>0){
                    if(tmp->left!=NULL){
                        if(tmp->left->data.compare(x)==0){
                            tmp->left = deleteNode(tmp->left,tmp->left->left , tmp->left->right);
                            return;
                        }
                        tmp = tmp->left;
                        continue;
                    }
                }
                else if(tmp->right!=NULL){
                        if(tmp->right->data.compare(x)==0){
                            tmp->right = deleteNode(tmp->right , tmp->right->left,tmp->right->left);
                            return;
                        }

                        tmp = tmp->right;
                        continue;
                    }
            }

        }

    }

}

bool BstStringSet::find(const string& x){

    Node* tmp = root;

    bool isDone = false;

    if(tmp==NULL){


                return false;
    }

    while(!isDone){


            if(tmp!=NULL){

                if(tmp->data.compare(x)==0){

                    return true;

                }
                else if(tmp->data.compare(x)>0){
                    if(tmp->left!=NULL){
                        if(tmp->left->data.compare(x)==0){
                            return true;
                        }
                        tmp = tmp->left;
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else if(tmp->right!=NULL){
                        if(tmp->right->data.compare(x)==0){
                            return true;
                        }

                        tmp = tmp->right;
                        continue;
                    }
                    else{
                        return false;
                    }
            }

    }

    return false;

}
//
void BstStringSet::insert(const string& x){

    Node* tmp = root;

    bool isDone = false;

    if(tmp==NULL){

                tmp = new Node(x);
                this->root = tmp;
                return;
            }

    while(!isDone){


            if(tmp!=NULL){

                if(tmp->data.compare(x)==0){
                    cout << "existed!"<< endl;
                    return;
                }
                else if(tmp->data.compare(x)>0){
                    if(tmp->left!=NULL){
                        tmp = tmp->left;
                        continue;
                    }
                    else{
                        tmp->left = new Node(x);
                        return;
                    }
                }
                else if(tmp->right!=NULL){
                        tmp = tmp->right;
                        continue;
                    }
                    else{
                        tmp->right = new Node(x);
                        return;
                    }
            }

    }



}





string BstStringSet::max()const{

        Node* tmp = root;
        if(tmp==NULL){
            return "empty!!!!!!!!!!!!";
        }
        while(true){
            if(tmp->right!=NULL){
                tmp = tmp->right;
            }
            else{
                return tmp->data;
            }
        }

}
//
//
string BstStringSet::min()const{

         Node* tmp = root;
        if(tmp==NULL){
            return "empty!!!!!!!!!!!!";
        }
        while(true){
            if(tmp->left!=NULL){
                tmp = tmp->left;
            }
            else{
                return tmp->data;
            }
        }

}

string BstStringSet::predeeessor(const string& x)const{

    Node* tmp = root;

    bool isDone = false;

    if(tmp==NULL){


                return "empty!";
    }

    while(!isDone){


            if(tmp!=NULL){

                if(tmp->data.compare(x)==0){

                    return tmp->left->data;

                }
                else if(tmp->data.compare(x)>0){
                    if(tmp->left!=NULL){
                        if(tmp->left->data.compare(x)==0){
                            return tmp->left->left->data;
                        }
                        tmp = tmp->left;
                        continue;
                    }
                }
                else if(tmp->right!=NULL){
                        if(tmp->right->data.compare(x)==0){
                            return tmp->data;
                        }

                        tmp = tmp->right;
                        continue;
                    }
            }

    }

}



void BstStringSet::printInorder()const{

   inOrder(root);


}

string BstStringSet::successor(const string& x)const{
    Node* tmp = root;

    bool isDone = false;

    if(tmp==NULL){


                return "empty!";
    }

    while(!isDone){


            if(tmp!=NULL){

                if(tmp->data.compare(x)==0){

                    return tmp->right->data;

                }
                else if(tmp->data.compare(x)>0){
                    if(tmp->left!=NULL){
                        if(tmp->left->data.compare(x)==0){
                            return tmp->data;
                        }
                        tmp = tmp->left;
                        continue;
                    }
                }
                else if(tmp->right!=NULL){
                        if(tmp->right->data.compare(x)==0){
                            return tmp->right->right->data;
                        }

                        tmp = tmp->right;
                        continue;
                    }
            }

    }


}

//BstStringSet::~BstStringSet(){
//
//    delete this->root;
//
//}










int main (){

    BstStringSet* a = new BstStringSet();

    a -> insert("asd");
    a->insert("a");
    a->insert("b");
    a->insert("as");

    a->printInorder();
    a->erase("b");
    //a->printInorder();

    return 0;
}
