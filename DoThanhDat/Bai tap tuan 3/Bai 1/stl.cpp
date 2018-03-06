#include <iostream>
#include <vector>

using namespace std;

int main(){
    int vt,gt;
    vector<int> A;
    vector<int>::iterator Iter;

    for(int i=1; i < 4; i++)
        A.push_back(i);
    for(int i=3; i < 6; i++)
        A.push_back(i);

    if(!A.empty())
        cout << "Not empty" << endl;
    else
        cout << "Empty" << endl;

    cout << "Length(A)->" << A.size() << endl;

    cout << "Phan tu can lay thu: ";
    cin >> vt;
    cout << "Element(A," << vt << ")->" << A.at(vt) << endl;

    cout << "Gia tri can chen la ";
    cin >>  gt;
    cout << "Vi tri can chen ";
    cin >> vt;
    A.insert(A.begin()+vt,gt);

    cout << "So can chen vao cuoi day:";
    cin >> gt;
    A.push_back(gt);

    cout << "Vi tri can xoa:";
    cin >> vt;
    A.erase(A.begin()+vt);

    for(Iter = A.begin(); Iter != A.end(); Iter++)
        cout<<" "<<*Iter;
        cout<<endl;

    return 0;
}
