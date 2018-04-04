#include<bits/stdc++.h>

using namespace std;


void print(queue<int> a){
	if(a.size()!=0){
		queue<int> b;
		b = a;
		cout << "(";
		for(int i = 0 ; i <=b.size() ;i++){
			cout << b.front() << ' ' ;
			b.pop();
		}
		cout << ")" << endl;
	}
	else{
		cout << "()" << endl; 
	}
	
}
int main(){
	
	queue<int> test ;
	test.push(10);
	test.push(5);
	cout << "enqueue(10) ,enqueue(5):";
	print(test);
	cout << "front() :";
	cout << test.front() << endl;
	cout << "dequeue() :" ;
	test.pop();
	print(test);
	cout <<"size() :" << test.size() << endl;
	cout << "dequeue() :";
	test.pop();
	print(test);
	
	if(test.size()==0)
		cout << "front() :" << "error" << endl;
	if(test.size()==0)
		cout << "dequeue():"<< "error" <<endl;
	
	cout << "isEmpty() :" << test.empty() <<endl;
	cout << "enqueue(8) :";
	test.push(8);
	print(test);
	
	
	
	
	
	
	
} 
