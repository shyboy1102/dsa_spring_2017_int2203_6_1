#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> x;
	//enqueue(10)
	x.push(10);
	//endqueue(5);
	x.push(5);
	//front()
	cout<<x.front()<<endl;
	//dequeue
	x.pop();
	//front()
	cout<<x.front()<<endl;
	//dequeue
	x.pop();
	//isEmpty()
	cout<<(x.empty()?"Empty":"Not empty")<<endl;
	//enqueue(8)
	x.push(8);
}
