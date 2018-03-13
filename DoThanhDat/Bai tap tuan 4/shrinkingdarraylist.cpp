#include <iostream>
using namespace std;

class DArraylist{
protected:
    int *a;
    int size;
    int last;

public:
    DArraylist(){
        a = NULL;
        size = 0;
        last = -1;
    }
    DArraylist(const DArraylist& object){
        size = object.size;
        a = new int[size];
        last = object.last;
        for(int i=0; i <= last; i++)
                a[i] = object.a[i];
    }
    ~DArraylist(){
        delete[] a;
    }
    const DArraylist& operator=(const DArraylist& object){
            delete[] a;
            a = new int[object.size];
            last = object.last;
            for(int i=0; i <= last; i++)
                a[i] = object.a[i];
            return *this;

    }
    void empty(){
        if(last == -1)
            cout << "Empty->True" << endl;
        else
            cout << "Empty->False" << endl;
    }
    int getlength(){
        return last+1;
    }
    int getsize(){
        return size;
    }
    int at(int i){
        return a[i-1];
    }
    void insert(int vt, int value){
        if(last+1 < size){
            for(int i=last+1; i>=vt; i--)
                a[i] = a[i-1];
            a[vt-1] = value;
            last++;
        }
       else{
            size = 2*size+1;
            int *p = new int[size];
            for(int i=0; i <= last; i++)
                p[i] = a[i];
            for(int i=last+1; i >= vt; i--)
                p[i] = p[i-1];
            p[vt-1] = value;
            last++;
            delete[] a;
            a = p;
        }
    }
    void append(int x){
        if(last+1 < size){
            a[last+1] = x;
            last++;
        }
        else{
            size = 2*size+1;
            int *p = new int[size];
            for(int i=0; i <= last; i++)
                p[i] = a[i];
            p[last+1] = x;
            last++;
            delete[] a;
            a = p;
        }
    }
    void erase(int vt){
        for(int i=vt-1; i < last; i++)
            a[i] = a[i+1];
        last--;
    }
    void show(){
        for(int i=0; i <= last; i++){
            cout << a[i] << endl;
        }
    }
};

class Shrinking : public DArraylist{
public:
    Shrinking(){
        a = NULL;
        size = 0;
        last = -1;
    }
    Shrinking(const Shrinking& object){
        size = object.size;
        a = new int[size];
        last = object.last;
        for(int i=0; i <= last; i++)
                a[i] = object.a[i];
    }
    ~Shrinking(){
        delete[] a;
    }
    void shrinkToFit(){
        if(last+1 < size){
            int *ptr = new int[last+1];
            for(int i=0; i <= last; i++)
                ptr[i] = a[i];
            delete[] a;
            a = ptr;
            size = last+1;
        }
    }
};

int main(){
     Shrinking arr;
    Shrinking crr;
    int x;
    int n;

    cout << "n=";
    cin >> n;

    for(int i=0;i<n;i++){
        cout << "x=";
        cin >> x;
        arr.append(x);
    }
    arr.insert(3,12);
    cout << "Lay ra phan tu 5:" << arr.at(5) << endl;
    arr.erase(2);
    cout << "Length=" << arr.getlength() << endl;
    arr.empty();

    Shrinking brr(arr);
    cout << "Brr:";
    brr.show();
    crr = arr;
    cout << "Crr:";
    crr.show();
    arr.shrinkToFit();
    cout << "size=" << arr.getsize();
    return 0;

}
