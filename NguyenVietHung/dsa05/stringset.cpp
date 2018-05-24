#include <iostream>
#include <string.h>

using namespace std;


class StringSet{
	private :
		string *element;
        int capacity, last;
    public :
    	StringSet(){
			last = -1;
			capacity = 0;
			element = NULL;
		}
		StringSet(int _capacity){
			last = -1;
			capacity = _capacity;
			element = new string[_capacity];
		}
		StringSet(const StringSet& asset){
			capacity = asset.capacity;
			last = asset.last;
			element = new string[capacity];
    		for (int i = 0; i <= last; i++){
        		element[i] = asset.element[i];
    			}
		}
		~StringSet(){
			delete [] element;
		}
		StringSet& operator=(const StringSet& asset) {
            this->element = asset.element;
            this->capacity = asset.capacity;
            this->last = asset.last;
            return *this;
        }
        bool empty() const {
			return (last == -1);
		}
		int size() const {
			return (last + 1);
		}
		int find(const string& x) const {
			for (int i = 0; i <= last; i++) {
        		if (x.compare(element[i]) == 0) return i;
    		}
    		return -1;
		}
		void erase(const string & x){
			for (int i = 0; i <= last; i++) {
        		if (element[i] == x) {
            		for (int j = i; j < last; j++) {
            			element[j] = element[ j + 1];
            		}
            last--;
        		}
    		}
		}
		void insert(const string & x){
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
    		}
			else{
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
		void print() const{
    		for(int i = 0; i <= last; i++){
        		cout << element[i] << endl;
    		}
		}	
};
	
int main() {
	StringSet str;
	str.insert("January");
	str.insert("Febuary");
	str.insert("March");
	str.insert("April");
	cout <<"empty = " << (str.empty() ? "true" : "false") << endl;
	cout <<"size = " << str.size() << endl;
	str.print();

	str.erase("January");
	str.print();

	StringSet str2;
	str2.insert("May");
	str2.insert("Jun");
	str2.insert("July");
	str.print();
	
	return 0;
}
	
