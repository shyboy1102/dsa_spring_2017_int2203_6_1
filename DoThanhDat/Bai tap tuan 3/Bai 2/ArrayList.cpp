#include <iostream>
using namespace std;

class ArrayList{
public:
    static const int MAX_SIZE = 100;
    ArrayList(){
        last = -1;
    }

    bool empty(){
        if(last == -1)
            return true;
        else
            return false;
    }
    int length(){
        return last+1;
    }
    void insert(int i, const int x){
        for(int t=last+1; t > i; t--){
            element[t] = element[t-1];
        }
        element[i] = x;
        last++;
    }
    void append(const int x){
        element[last+1] = x;
        last++;
    }
    void erase(int i){
        for(int t=i; t < last+1; t++){
            element[t] = element[t+1];
        }
        last--;
    }
    int& at(int i) const{
       int n = element[i];
       return n;
    }
    void display(){
        for(int i=0; i < last+1; i++){
            cout << " " << element[i];
        }
        cout << endl;
    }

private:
    int element[MAX_SIZE];
    int last;
};

int main(){
    ArrayList arr;

    //Gan gia tri cho tung phan tu cua mang
    for(int i=1; i < 4; i++)
        arr.append(i);
    for(int i=3; i < 6; i++)
        arr.append(i);
    arr.display();

    cout << "Arr is empty:" ;
    arr.empty()?cout<<"false":cout<<"true";
    cout<<endl;

    cout << "Length(arr)->" << arr.length() << endl;
    cout << "Element(arr,0)->" << arr.at(0) << endl;

    arr.insert(2,10);
    arr.display();

    arr.append(-5);
    arr.display();

    arr.erase(1);
    arr.display();

    return 0;
}
