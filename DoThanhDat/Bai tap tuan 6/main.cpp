#include <iostream>
#include <fstream>
#include "strlist.cpp"
using namespace std;

int main(){

    StringLinkedList str;
    StringLinkedList str1("File.txt");
    cout << str.empty() << endl;

    str.addFirst("do thanh dat");
    str.addFirst("do thanh ");
    str.addFirst("datprince");

    str.addLast("anhdat");
    cout << "Last:" << str.last();

    str.removeFirst();
    str.print();
    str1.print();
    return 0;
}
