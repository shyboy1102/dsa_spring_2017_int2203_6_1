#include <iostream>

using namespace std;

main() {
    int p;
    while(p<0||p>4) {
        cout << "Enter p: ";
        cin >> p;
    }
    if(p==0)
        cout << "Black";
    else if(p==1)
        cout << "Blue";
    else if(p==2)
        cout<< "Green";
    else if(p==3)
        cout<< "Cyan";
    else if(p==4)
        cout<< "Magenta";
   return 0;
}
