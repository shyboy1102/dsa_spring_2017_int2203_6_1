#include <iostream>
#include <queue>

using namespace std;
void enqueue(queue<int> list, int value){
	list.push(value);
	
}
void dequeue(queue<int> list){
	while(!list.empty()){
		cout << ' ' << list.front();
		list.pop();
	}
	if(list.empty())
		cout << "Hang doi rong!";
	
}
void print(queue<int> list){
	while(!list.empty()){
		cout << ' ' << list.front();
		list.pop();
	}
}
int main(){
	queue<int> L;
	cout << " Sau khi enqueue(10) duoc list L: " ;
	enqueue(L, 10);
	print(L);
	cout << "\n Sau khi enqueue(5) duoc list L: " ;
	enqueue(L, 5);
	print(L);
	cout <<"\n front(): " << L.front();
	cout << "\n Sau khi dequeue() duoc list L: " ;
	dequeue(L);
	cout << "\n size: " << L.size();
	cout << "\n Sau khi dequeue() duoc list L: " ;
	dequeue(L);
	cout << "\n Sau khi dequeue() duoc list L: " ;
	dequeue(L);
	cout << "\n Sau khi enqueue(8) duoc list L: " ;
	enqueue(L, 8);
	print(L);
	
	return 0;
}
