#include <iostream>
#include "strlist.h"
#include <fstream>
using namespace std;

int main()
{
    StringLinkedList L("strList.txt");
    cout << "L: " << endl;
    L.print();

    cout << "L.addFirst(""df"")" << endl;
    cout << "L.addLast(""md"")" << endl;
    L.addFirst("df");
    L.addLast("md");
    cout << "L:" << endl;
    L.print();

    cout << "L.removeFirst()" << endl;
    L.removeFirst();
    cout << "L:" << endl;
    L.print();

    cout << "L.first(): " << L.first() << endl;
    cout << "L.last(): " << L.last() << endl;

    cout << "L.empty()" << L.empty() << endl;

    L.~StringLinkedList();
    cout << "L.~StringLinkedList()" << endl;
    cout << "L:" << endl;
    L.print();
    return 0;
}
