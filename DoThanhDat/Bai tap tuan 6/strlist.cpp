#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class StringNode{
private:
    string data;
    StringNode *next;
    friend class StringLinkedList;
};

class StringLinkedList{
public:
    StringLinkedList(){
            head = tail = NULL;
    }
    StringLinkedList(char *filename): head(NULL), tail(NULL){
        ifstream f(filename);
        string data;
     //   StringNode *current =  head;
        while(f >> data){
           this->addLast(data);
        }
        f.close();
    }
    ~StringLinkedList(){
        StringNode *current = head;
        while(current != NULL){
            StringNode *next = current->next;
            delete current;
            current = next;
        }
    }
    bool empty() const{
        if(head == tail)
            return true;
        else
            return false;
    }
    void addFirst(const string& e){
        StringNode *q ;
        q = new StringNode();
        q->data = e;
        if(head == NULL){
            head = q;
            tail = q;
        }
        else{
        q->next = head;
        head = q;
        }

    }
    const string& first() const{
        return head->data;
    }
    void removeFirst(){
        if(head == NULL)
            cout << "List empty";
        else{
            StringNode *q = head;
            head = head->next;
            delete q;
        }
    }
    void addLast(const string& e){
        StringNode *q;
        q = new StringNode();
        q->data = e;
        if(head == NULL){
            head = q;
            tail = q;
        }
        else{
        q->next  = NULL;
        tail->next = q;
        tail = q;
        }
    }
    const string& last() const{
        return tail->data;
    }
  void print() {
        StringNode *current = head;
        while(current != NULL){
            cout << current->data << endl;
            current = current->next;
        }
  }
private:
    StringNode *head;
    StringNode *tail;
};
