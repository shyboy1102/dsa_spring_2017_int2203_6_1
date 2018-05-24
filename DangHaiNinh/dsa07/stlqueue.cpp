#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> my_queue;
	my_queue.push(1);
	cout << "\n\tenqueue(1) -> " << my_queue.front() << endl;;
	
	my_queue.push(2);
	cout << "\n\tenqueue(2) -> " << my_queue.front() << " " << my_queue.back() << endl;
	
	cout << "\n\tfront() -> " << my_queue.front() << endl;
	
	if(!my_queue.empty())
	{
		my_queue.pop();
		cout << "\n\tdequeue() -> " << my_queue.front() << endl;
	}

	cout << "\n\tsize() -> " << my_queue.size() << endl;

	my_queue.pop();
	cout << "\n\tdequeue() -> ";
	(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "\n\tEmpty Queue") << endl;

	cout << "\n\tfront() -> " ;
	(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "\n\tError: Empty Queue") << endl;
	if(!my_queue.empty())
	{
		my_queue.pop();
		cout << "\n\tdequeue() -> ";
		(!my_queue.empty() ? cout << my_queue.front() << endl : cout << "\n\tError: Empty Queue") << endl;
	}
	else
	{
		cout << "\n\tdequeue() -> Error: Empty Queue" << endl;
	}
	cout << "\n\tisEmpty() -> " << my_queue.empty() << endl;
	my_queue.push(3);
	cout << "\n\tenqueue(3) -> " << my_queue.back() << endl;
	return 0;
}