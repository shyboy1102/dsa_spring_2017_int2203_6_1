#include <iostream>
#include"strlist.h"
//#include"strlist.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
main() {
	StringLinkedList str1;
	if(str1.empty())
		cout<<"danh sach rong!"<<endl;
	else
		cout<<"danh sach khong rong!"<<endl;
	str1.addFirst("monday");
	str1.addFirst("friday");
	str1.addFirst("tuesday");
	str1.addLast("sunday");
	cout<<"StringLinkedList 1:"<<endl;
	str1.print();
	str1.removeFirst();
	cout<<"StringLinkedList 1 sau khi loai phan tu dau:"<<endl;
	str1.print();
	cout<<"head->"<<str1.first()<<endl;
	cout<<"last->"<<str1.last()<<endl;
	
	StringLinkedList str2("filename.txt");
	if(str2.empty())
		cout<<"danh sach rong!"<<endl;
	else
		cout<<"danh sach khong rong!"<<endl;
	cout<<"StringLinkedList 2:"<<endl;
	str2.print();
}
