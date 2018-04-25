#include <iostream>
#include "strlist.h"
#include "strlist.cpp"
using namespace std;

int main(){
	StringLinkedList strlist("numbers.txt");
	strlist.print();
}
