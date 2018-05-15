#include<iostream>
#include<assert.h>
using namespace std;

class DArrayList{
	public:
		DArrayList(){
			element=NULL;
			size=0;
			last=-1;
		}
		
		
		DArrayList(const DArrayList &dal1){
			element=new int[dal1.size];
			size=dal1.size;
			last=dal1.last;
			for(int i=0;i<=last;i++){
				element[i]=dal1.element[i];
			}
		}
		
		
		~DArrayList(){
			delete[] element;
		}
		
		
		DArrayList operator=(const DArrayList &dal1){
			if(size!=dal1.size){
				delete[] element;
				element=new int[dal1.size];
				size=dal1.size;
			}
			last=dal1.last;
			for(int i=0;i<=last;i++){
				element[i]=dal1.element[i];
			}
			return *this;
		}
		
		
		bool empty(){
			if(last==-1){
				return true;
			}
			else
				return false;
		}
		
		
		int length(){
			return last+1;
		}
		
		void insert(const int x, int i){
			assert(i>0&&i<=last);
			if(length()<size){
				last++;
				for(int k=last+1;k>i;k--){
					element[k]=element[k-1];
				}
				element[i]=x;
			}
			else{
				int* current = new int[2*size+1];
				for(int k=0;k<i;k++){
					current[k] = element[k];					
				}
				current[i]=x;
				for(int k=i+1;k<=last+1;k++){
					current[k]=element[k-1];
				}
				last++;
				size = 2*size+1;
				delete[] element;
				element = current;
			}
		}
		
		void append(const int x){
			if(length()<size){
				last++;
				element[last]=x;
			}
			else{
				int* current = new int[2*size+1];
				for(int i=0;i<=last;i++){
					current[i] = element[i];
				}
				last++;
				current[last]=x;
				size = 2*size+1;
				delete[] element;
				element = current;
			}
		}
		
		void erase(int i){
			for(int k=i;k<last+1;k++){
				element[k]=element[k+1];
			}
			last--;
		}
		
		int& at(int i){
			return element[i];
		}
		 
		void print(){
			cout<<"A=(";
			for(int i=0;i<last;i++){
				cout<<element[i]<<",";
			}
			cout<<element[last];
			cout<<")"<<endl;
		}
		
		int sizes(){
			return size;
		}
		
		
		protected:
			int* element;
			int size;
			int last;
};
	


