#include<iostream>
#include <string>
#include<assert.h>
using namespace std;

class StringSet{
	public:
		StringSet(){
			element=NULL;
			capacity=0;
			last=-1;
		}
		
		StringSet(int capacity){
			element=new string[capacity];
			assert(element!=NULL);
			this->capacity=capacity;
			last=-1;
		}
		
		StringSet(const StringSet& asset){
			element=new string[asset.capacity];
			capacity=asset.capacity;
			last=asset.last;
			for(int i=0;i<=last;i++){
				element[i]=asset.element[i];
			}
		}
		
		~StringSet(){
			delete[] element;
		}
		
		bool empty() const{
			if(last==-1)
				return true;
			else
				return false; 
		}
		
		int size() const{
			return last+1;
		}
		
		int find(const string & x) const{
			for(int i=0;i<=last;i++){
				if(element[i]==x)
					return i+1;
				else
					return -1;
			}	
		}
		
		void erase(const string & x){
			int current;
			for(int i=0;i<last+1;i++){
				if(element[i]==x)
					current=i;
			}
			for(int k=current;k<last+1;k++){
				element[k]=element[k+1];
			}
			last--;
		}
		
		void insert(const string & x){
			if(last==-1){
				last++;
				element[last]=x;
			}
			else{
				if(size()<capacity){
					last++;
					element[last]=x;
				}
				else{
					string* temp = new string[2*capacity+1];
					for(int k=0;k<=last;k++){
						temp[k]=element[k];	
					}
					temp[last+1]=x;
					delete[] element;
					element=temp;
					last++;
					capacity=2*capacity+1;
				}	
			}
			
			for(int i=0;i<=last;i++){
		
				for(int j=0;j<=last;j++){
				
					if(element[i]<element[j]){
						swap(element[i],element[j]);
					}
				}
			}
			
			for(int i=0;i<=last;i++){
				for(int k=0;k<=last;k++){
					if(element[i]==element[k]&&i!=k)
						erase(element[i]);
				}
			}
		}
		
		StringSet& operator=(const StringSet& asset){
			if(capacity!=asset.capacity){
				delete[ ] element;
				element= new string[asset.capacity];
				capacity=asset.capacity;
			}
			last=asset.last;
			for(int i=0;i<=last;i++){
				element[i]=asset.element[i];
			}
			return *this;
		}
		
		const StringSet operator+ (const StringSet & asset){
			StringSet temp;
			temp.capacity = capacity+asset.capacity;
			temp.element = new string[temp.capacity];
			for(int i=0;i<=last;i++){
				temp.insert(element[i]);
			}
			
			for(int i=0;i<=asset.last;i++){
				temp.insert(asset.element[i]);
			}
			return temp;
		}
		
		void print(){
			for(int i=0;i<last+1;i++){
				cout<<element[i]<<endl;
			}
		}
		
		private:
			string* element;
			int capacity;
			int last;
};
main(){
	StringSet S(3) ;
	StringSet S1;
	StringSet S2(10);
	StringSet S3;
	S.insert("april");
	S.insert("april");
	S.insert("february");
	S.insert("march");
	S.insert("january");
	cout<<"Cac phan tu trong S la:"<<endl;
	S.print();
	
	if(S.empty())
		cout<<"Mang rong!"<<endl;
	else
		cout<<"Mang khong rong!"<<endl;
	
	cout<<"Do dai mang S:"<<S.size()<<endl;
	
	S.erase("february");
	cout<<"Cac phan tu trong mang sau khi xoa la:"<<endl;
	S.print();

	S1=S;
	cout<<"Cac phan tu trong mang S1 voi S1=S la:"<<endl;
	S1.print();
	
	S2.insert("sunday");
	S2.insert("Thursday");
	S2.insert("friday");
	cout<<"Cac phan tu trong mang S2 la:"<<endl;
	S2.print();
	
	S3=S+S2;
	cout<<"Cac phan tu trong mang S3=S+S2 la:"<<endl;
	S3.print();
	
}
