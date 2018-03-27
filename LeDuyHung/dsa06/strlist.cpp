#include <iostream>
#include "strlist.h"
#include <fstream>

using namespace std;

StringLinkedList::StringLinkedList() {
    head = NULL;
    tail = NULL;
}

StringLinkedList::StringLinkedList(char * fileName) {
    ifstream file(fileName);
    string line;
    head = NULL;
	tail = NULL;
    while(getline(file, line))
    {
        addLast(line);
    }
    file.close();
}

StringLinkedList::~StringLinkedList() {
    StringNode * temp;
    while (head != NULL) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool StringLinkedList::empty() const {
	return head == NULL;
}

const string& StringLinkedList::first() const {
    if(!empty()) {
        return head->data;
    }
}

void StringLinkedList::addFirst(const string & e) {
	StringNode * q = new StringNode();
	q->data = e;
	q->next = head;
	head = q;
	if(head->next == NULL) {
        tail = head;
	}
}

void StringLinkedList::removeFirst() {
    if(head == NULL) {
        cout << "Empty list" << endl;
    }
    else {
        StringNode * t = head;
		head = head->next;
		delete t;
    }
}

const string& StringLinkedList::last() const {
    if(!empty()) {
        return tail->data;
    }
}

void StringLinkedList::addLast(const string & e) {
	if(empty()) {
		StringNode * q = new StringNode();
		q->data = e;
		q->next = NULL;
		tail = q;
		head = tail;
	}
	else{
		StringNode * q = new StringNode();
		q->data = e;
		q->next = NULL;
		tail->next = q;
		tail = q;
	}
}

void StringLinkedList::print() const {
    if(empty()) {
        cout << "Empty list" << endl;
    }
	else {
		StringNode * temp = head;
		while(temp != tail) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << tail->data << endl;
	}
}
