#include<iostream>
#include<string>
#include<fstream>
#include"strlist.h"
#include <string.h>
using namespace std;

StringLinkedList :: StringLinkedList(){
	head = NULL;
	tail = NULL;
}

StringLinkedList :: StringLinkedList(char* filename){
	ifstream file(filename);
    string line;
    head = NULL;
	tail = NULL;
    while(getline(file, line))
    {
        addLast(line);
    }
    file.close();

}

StringLinkedList :: ~StringLinkedList(){
	StringNode* current;
	while(head!=NULL){
		current = head->next;
		delete head;
		head = current;
	}
}

bool StringLinkedList :: empty() const{
	if(head==NULL)
		return true;
	else
	 	return false;
}

const string& StringLinkedList :: first() const{
	return head->data;
}

void StringLinkedList :: addFirst(const string& e){
	StringNode* current = new StringNode();
	current->data = e;
	current->next = head;
	if(empty()){
		head = current;
		tail = current;
	}
	else
		head = current;
}

void StringLinkedList :: removeFirst(){
	if(empty()) {
		cout<<"Danh sach rong"<<endl;
	}
	else{
		StringNode* current;
		current = head;
		head = head->next;
		delete current;
	}
}

const string& StringLinkedList :: last() const{	
	return tail->data;
}

void StringLinkedList :: addLast(const string& e){
	StringNode* current = new StringNode();
	current->data = e;
	current->next = NULL;
	if(empty()){
		head = current;
		tail = current;
	}
	else{
		tail->next = current;
		tail = current;
	}
}

void StringLinkedList :: print() const{
	StringNode* current;
	for(current=head; current!=NULL;current=current->next){
		cout<<current->data<<endl;
	}
	
}
