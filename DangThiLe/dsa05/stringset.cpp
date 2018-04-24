#include <iostream>
#include <string.h>

using namespace std;


class StringSet{
public:
	StringSet();
	StringSet(int _capacity);
	StringSet(const StringSet& asset);
	~StringSet();
	bool empty() const;
	int size() const;
	int find(const string & x ) const;
	void erase(const string & x);
	void insert(const string & x);
	StringSet& operator=(const StringSet& asset);
	const StringSet operator+(const StringSet& asset);
	void print() const;
private:
	string * element;
	int capacity;
	int last;
};

StringSet::StringSet(){
	last = -1;
	capacity = 0;
	element = NULL;
}
StringSet::StringSet(int _capacity){
	last = -1;
	capacity = _capacity;
	element = new string[_capacity];
}
StringSet::StringSet(const StringSet& asset){
	capacity = asset.capacity;
	last = asset.last;
	element = new string[capacity];
    for (int i = 0; i <= last; i++){
        element[i] = asset.element[i];
    }
}
StringSet::~StringSet(){
	delete [] element;
}
StringSet& StringSet::operator=(const StringSet& asset){
	capacity = asset.capacity;
    last = asset.last;
    element = new string[capacity];
    for (int i = 0; i <= last; i++)
    {
        element[i] = asset.element[i];
    }
    return *this;
}

bool StringSet::empty() const {
	return (last == -1);
}
int StringSet::size() const {
	return (last + 1);
}
int StringSet::find(const string& x) const {
	for (int i = 0; i <= last; i++)
    {
        if (x.compare(element[i]) == 0) return i;
    }
    return -1;
}
void StringSet::erase(const string & x){
	for (int i = 0; i <= last; i++)
    {
        if (element[i] == x)
        {
            for (int j = i; j < last; j++) 
            {
                element[j] = element[ j + 1];
            }
            last--;
        }
    }
}
void StringSet::insert(const string & x){
	if (element == NULL){
        string * st = new string[1];
        st[0] = x;
        element = st;
        last = 0;
        capacity = 1;
        return;
    }
    if(last + 1 == capacity){
        capacity *= 2;
        string * st = new string[capacity];
        int i = 0;

        while (element[i].compare(x) == -1 && i <= last){
            st[i] = element[i];
            i++;
        }
        st[i] = x;
        for(i = i + 1; i <= last+1; i++){
            st[i] = element[i-1];
        }
        delete[] element;
        element = st;
        last++;
    }else{
        int position = 0;
        while(element[position].compare(x) == -1 && position <= last){
            position++;
        }
        for(int j = last + 1; j > position; j--){
            element[j] = element[j-1];
        }
        element[position] = x;
        last++;
    }
}
void StringSet::print() const{
    for(int i = 0; i <= last; i++){
        cout << element[i] << endl;
    }
}

int main(){
	StringSet a;
	a.insert("md");
    a.insert("cv");
    a.print();
    cout << "a.size() = " << a.size() << endl;
    cout << "a.empty() = " << a.empty() << endl;
    
    a.erase("cv");
    a.print();
    
	StringSet b = a;
    b.print();
	return 0;
}
