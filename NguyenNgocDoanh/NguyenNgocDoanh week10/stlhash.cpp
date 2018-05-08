#include<iostream>
#include<string>
#include<array>
#include<unordered_set>
#include<set>
using namespace std;

int main(){
	unordered_set<string> myset = {"yellow", "green","blue"};
	array<string> myarray = {"black", "white"};
	string mystring = "red";

	myset.insert(mystring);
	myset.insert(mystring+"dish");
	myset.insert(myarray.begin(), myarray.end());

	cout << "my set contains: ";
	for(const string & x : myset)
		cout << " " << x;
	cout << endl;
	return 0;
}
