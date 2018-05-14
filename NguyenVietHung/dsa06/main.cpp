#include<iostream>
#include "strlist.h"
#include"strlist.cpp"

using namespace std;

int main() {
	StringLinkedList s1("test.txt");
	cout << "LinkedList1: ";
	s1.print();
    cout << "s1.head = " << s1.first() << endl;
	cout << "s1.tail = " << s1.last() << endl;
    cout << endl;

	StringLinkedList s2;
	s2.addFirst("Lion");
	s2.addFirst("Monkey");
	s2.addFirst("Bird");
	s2.addFirst("Pig");
	s2.addFirst("Dog");

    s2.addLast("Cat");
	s2.addLast("Mouse");

	cout << "LinkedList2: ";
	s2.print();

    cout << "s2.empty() -> " << (s2.empty() ? "true" : "false") << endl;

	s2.removeFirst();
	cout << "s2.removeFirst() -> ";
    cout << "LinkedList2: ";
	s2.print();

	return 0;
}
