#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;


const int TABLE_SIZE = 128;

class HashEntry{
	private:
		string key;
		string value;
		HashEntry * next;
	public:
		HashEntry(const string & key, const string & value){
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
	friend class HashMap;
};

class HashMap{
	public:
		HashMap();
		HashMap(char *filename);
		~HashMap();
		void insert(const string & key, const string & value); // puts key key into the hash table
		bool search(const string & key); // searches for key key in the hash table
		void remove(const string & key); // removes key key from the hash table
		void print_hash();
		void readfile(char * filename);
	private:
		HashEntry ** array;	
		long long int atoi(string key);
		int hashCode(string key);
		void print_linkedlist(HashEntry * h);
		void insert_linkedlist(HashEntry * h, HashEntry * node);
};


HashMap::HashMap(){
	array = new HashEntry*[TABLE_SIZE];
	for(int i=0;i<TABLE_SIZE;i++){
		array[i] = NULL;
	}
}

void HashMap::readfile(char * filename){
	ifstream file(filename);
	string word;
	if(file.is_open()){
		while(file >> word){
			if(!search(word))
				cout << word << " ";
		}
		cout << endl;
	}
}

HashMap::HashMap(char * filename){
	array = new HashEntry*[TABLE_SIZE];
	for(int i=0;i<TABLE_SIZE;i++){
		array[i] = NULL;
	}

	ifstream file(filename);
	string line;
	if(file.is_open()){
		while(!file.eof()){
			getline(file,line);
			string s1 = line.substr(0,line.length()-2);
			string s2 = line.substr(line.length()-1,1);
			insert(s1,s2);
		}
	}
}

long long int HashMap::atoi(string key){
	long long int temp = 0;
	int pos = 0;
	int temp1 = key.length()-1;
	while(pos < key.length()){
		int k = (int)key.substr(pos,1)[0]; 
		temp += k*pow(37,temp1--);
		pos++;
	}
	return temp;
}


int HashMap::hashCode(string key){
	return atoi(key) % TABLE_SIZE;
}

void HashMap::insert_linkedlist(HashEntry * h, HashEntry * node){
	while(h->next != NULL)
		h = h->next;
	h->next = node;
}

void HashMap::insert(const string & key, const string & value){
	int hashIndex = hashCode(key);

	if(array[hashIndex] == NULL){
		array[hashIndex] = new HashEntry(key,value);
	}
	else{
		insert_linkedlist(array[hashIndex], new HashEntry(key, value));
	}
}

bool HashMap::search(const string & key){
	int hashIndex = hashCode(key);

	if(array[hashIndex] == NULL)
		return false;
	else{
		HashEntry * h = array[hashIndex];
		while(h != NULL){
			if(!h->key.compare(key))
				return true;
			else
				h = h->next;	
		}			
		return false;
	}
}

void HashMap::remove(const string & key){
	int hashIndex = hashCode(key);

	if(search(key)){
		if(array[hashIndex]->next == NULL)
			array[hashIndex] = NULL;
		else{
			HashEntry * h = array[hashIndex];
			while(h->next->key != key)
				h = h->next;
			h->next = h->next->next;
		}
	}
	else
		cout << key << " khong co trong hash table" << endl;
}

void HashMap::print_linkedlist(HashEntry * h){
	while(h->next != NULL){
		cout << h->key << " --> ";
		h = h->next;
	}

	cout << h->key << endl;
}

void HashMap::print_hash(){
	for(int i=0;i<TABLE_SIZE;i++)
		if(array[i] != NULL){
			print_linkedlist(array[i]);
		}
		else
			cout << "." << endl;
}


int main(){
	HashMap * h = new HashMap((char *)"dictionary.txt");
	cout << h->search("outline") << endl;
	h->remove("appropriate");
	h->print_hash();
	cout << "word is not in dictionary : ";
	h->readfile((char *)"input.txt");
	return 0;
}

