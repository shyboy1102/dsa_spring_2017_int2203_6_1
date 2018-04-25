#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<int> my_queue;
	my_queue.push(10);
	cout << "enqueue(10) -> " << my_queue.front() << endl;;
	
	my_queue.push(5);
	cout << "enqueue(5) -> " << my_queue.front() << " " << my_queue.back() << endl;
	
	cout << "front() -> " << my_queue.front() << endl;
	
	if(!my_queue.empty()){
		my_queue.pop();
		cout << "dequeue() -> " << my_queue.front() << endl;
	}

	cout << "size() -> " << my_queue.size() << endl;

	my_queue.pop();
	cout << "dequeue() -> ";
	(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "Empty Queue") << endl;

	cout << "front() -> " ;
	(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "Error: Empty Queue") << endl;
	if(!my_queue.empty()){
		my_queue.pop();
		cout << "dequeue() -> ";
		(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "Error: Empty Queue") << endl;
	}
	else
		cout << "dequeue() -> Error: Empty Queue" << endl;
	cout << "isEmpty() -> " << my_queue.empty() << endl;
	my_queue.push(8);
	cout << "enqueue(8) -> " << my_queue.back() << endl;
	return 0;
}