#include <iostream>
using namespace std;

class StringSet{
public:
    StringSet(){
        capacity = 0;
        last = -1;
        element = NULL;
    }
    StringSet(int _capacity){
        capacity = _capacity;
        element = new string[capacity];
    }
    StringSet(const StringSet& st){
        capacity = st.capacity;
        last = st.last;
        for(int i=0; i <= last; i++)
            element[i] = st.element[i];

    }
    ~StringSet(){
        delete[] element;
    }

    bool empty() const{
        if(last == -1)
            cout << "Empty -> True";
        else
            cout << "Empty -> False";
    }
    int size() const{
        return last+1;
    }
    void write(){
        string s;
        while(s != "."){
            cin >> s;
            if(last+1 < capacity){
                last++;
                element[last] = s;
            }
            else{
                capacity = 2*capacity + 1;
                string *ptr = new string[capacity];
                for(int i=0; i <= last; i++)
                    ptr[i] = element[i];
                ptr[last+1] = s;
                last++;
                delete[] element;
                element = new string[capacity];
                element = ptr;
            }
        }
    }

    void sort(){
        string tg;
        for(int i=0; i < last; i++){
            for(int j=i+1; j <= last; j++){
                if(element[i] > element[j]){
                    tg = element[i];
                    element[i] = element[j];
                    element[j] = tg;
                }
            }
        }
    }
    //Find sau khi da sort
    int find(const string& x) const {
        int left = 0;
        int right = last;
        while(left < right){
            int mid = (left+right)/2;
            if(element[mid].compare(x) == 0)
                return mid;
            else if(element[mid].compare(x) > 0)
                right = mid-1;
            else if(element[mid].compare(x) < 0)
                left = mid+1;
        }
        return -1;
    }
    void erase(const string& s){
        for(int i=0; i <= last; i++){
            if(element[i] == s){
                int j=i;
                while(j != last){
                    element[j] = element[j+1];
                    j++;
                }
                last--;
            }
        }
    }
    void insert(const string& s){
        int kt=0;
        for(int i=0; i <= last; i++){
            if(element[i] == s){
                cout << "Chuoi da ton tai" << endl;
                kt = 1;
            }
        }
        if(kt == 0){
            if(last+1 < capacity){
                last++;
                element[last] = s;
            }
            else{
                capacity = 2*capacity + 1;
                string *ptr = new string[capacity];
                for(int i=0; i <= last; i++)
                    ptr[i] = element[i];
                ptr[last+1] = s;
                last++;
                delete[] element;
                element = new string[capacity];
                element = ptr;
            }
        }
    }
    StringSet& operator=(const StringSet& st){
        delete[] element;
        capacity = st.capacity;
        last = st.last;
        element = new string[capacity];
        for(int i=0; i <= last; i++){
            element[i] = st.element[i];
        }
        return *this;
    }
    const StringSet operator+(const StringSet& st){
        for(int i=0; i <= st.last; i++){
            if(last+1 < capacity){
                last++;
                element[last] = st.element[i];
            }
            else{
                capacity = 2*capacity + 1;
                string *ptr = new string[capacity];
                for(int i=0; i <= last; i++)
                    ptr[i] = element[i];
                ptr[last+1] = st.element[i];
                last++;
                delete[] element;
                element = new string[capacity];
                element = ptr;
            }
        }
        return *this;
    }
    void display(){
        for(int i=0; i <= last; i++){
            if(element[i] == ".")  continue;
            cout << element[i] << endl;
        }
    }
private:
    string *element;
    int capacity;
    int last;
};

int main(){
    StringSet st2,st;
    StringSet st1(100);

    cout << "Nhap chuoi 1:";
    st1.write();
    cout << "Nhap chuoi 2:" ;
    st2.write();
    st2.insert("do");
    st1.sort();
    st2.sort();
   // cout << "Vi tri" << st1.find("do") << endl;
   // st1.insert("do");
    st = st1;
    cout << "Hien thi st1:";
    st1.display();
    cout << "Hien thi st2:" << endl;
    st2.display();

}
