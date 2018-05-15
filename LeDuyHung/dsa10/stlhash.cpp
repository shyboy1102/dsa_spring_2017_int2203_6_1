#include<iostream>
#include<unordered_set>

using namespace std;

int main() {
	unordered_set<string> month = {"june", "november", "may"};
	month.insert("august");
	month.erase("june");
	cout << "My months: ";
	for(const string & m : month) {
		cout << m << " ";
	}
	cout << endl;
	return 0;
}
