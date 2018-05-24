#include<iostream>
#include "darraylist.cpp"
using namespace std;

class ShrinkingDArrayList:public DArrayList {
	public:
		ShrinkingDArrayList(){
			element=NULL;
			size=0;
			last=-1;
		}
		
		~ShrinkingDArrayList(){
			delete element;
		}
		
		void shinkToFit(){
			size=last+1;
			int *p = new int[size];
       		for(int i = 0; i <= last; i++) {
            	p[i] = element[i];
            }
            delete[] element;
            element = p;
		}
};
main(){
	ShrinkingDArrayList A;
	A.append(1);
	A.append(2);
	A.append(3);
	A.append(3);
	A.append(4);
	A.append(5);
	A.print();
	cout<<A.sizes()<<endl;
	A.shinkToFit();
	cout<<A.sizes()<<endl;
	if(A.empty()){
		cout<<"empty(A)-> true"<<endl;
	}
	else
		cout<<"empty(A)-> false"<<endl;
	
	cout<<"length(A)-> "<<A.length()<<endl;
	
	cout<<"element(A,0)-> "<<A.at(0)<<endl;
	
	cout<<"element(A,2)-> "<<A.at(2)<<endl;
	
	A.insert(10,2);
	cout<<"insert(A,2,10)-> ";
	A.print();
	
	A.append(-5);
	cout<<"append(A,-5)-> ";
	A.print();
	
	A.erase(3);
	cout<<"del(A,3)-> ";
	A.print();
	
	A.erase(1);
	cout<<"del(A,1)-> ";
	A.print();
	
}
