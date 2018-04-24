#include <iostream>
#include <string>
#include "strlist.h"
#include "strlist.cpp"

using namespace std;

int main(){
	StringLinkedList s = StringLinkedList();
	
	s.addFirst("aaa");
	s.addFirst("aaa");
	s.addLast("111");
	cout << s.empty() << endl;
	s.print();
	s.removeFirst();
	s.print();
	cout << s.first(); 
	return 0;
}
