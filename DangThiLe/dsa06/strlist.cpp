#include <iostream>
#include "strlist.h"

StringLinkedList::StringLinkedList(){
	head = NULL;
	tail = NULL;
	
}
StringLinkedList::StringLinkedList(char * filename){
	
}
StringLinkedList::~StringLinkedList(){
	while(!empty())
		removeFirst();
}
bool StringLinkedList::empty() const {
	return (head == NULL);
}
const string& StringLinkedList::first() const {
	return (head->data);
}
void StringLinkedList::addFirst(const string & e){
	StringNode* p = new StringNode;
	p->data = e;
	if(!empty()){
		p->next = head;
	}
	else {
		p->next = NULL;
		tail = p;
	}
	head = p;
	
}
void StringLinkedList::removeFirst(){
	StringNode* remove;
	remove = head;
	if(head == tail){
		head = NULL;
		tail = NULL;
	}
	else{
		head = head->next;
	}
	delete remove;
}
const string& StringLinkedList::last() const {
	return tail->data;
}
void StringLinkedList::addLast(const string & e){
	StringNode* last = new StringNode;
	last->data = e;
	last->next = NULL;
	if(head == NULL)
		head = last;
	else{
		StringNode* node = head;
		while(node->next != NULL)
			node = node->next;
		node->next = last;
	}
	
}
void StringLinkedList::print() const {
	StringNode* node = head;
	while(node != NULL){
		cout << node->data << endl;
		node = node->next;
	}
}
