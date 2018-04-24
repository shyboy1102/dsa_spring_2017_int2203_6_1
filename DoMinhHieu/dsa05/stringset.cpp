#include <iostream>
#include <string>
using namespace std;
using std::string;


class StringSet{
	private:
		string *element;
		int capacity,last;
	public:
		StringSet(){
			element=NULL;
			capacity=0;
			last=-1;
		}
		//Khoi tao co toi da capacity phan tu
		StringSet(int _capacity){
			element= new string[_capacity];
			capacity=_capacity;
			last=-1;
		}
		//Kien tao sao chep
		StringSet(const StringSet& asset){
			element=asset.element;
			capacity=asset.capacity;
			last=asset.last;
		}
		//Giai phong bo nho
		~StringSet(){
			delete element;
		}
		//Kiem tra rong
		bool empty() const{
			return last==-1;
		} 
		
		//Dem so phan tu
		int size() const{
			return last+1;
		}
		//Tim xau x
		int find(const string &x) const{
			int left=0;
			int right=last;
			while(left<=right){
				int mid=(left+right)/2;
				if(x==element[mid])
					return mid;
				else if (x<element[mid])
					right=mid-1;
				else if(x>element[mid])
					left=mid+1;
			}
			
			return -1;
		}
		//Xoa phan tu gia tri bang x
		void erase(const string &x){
			for(int i=0;i<last+1;i++)
			{
				if(element[i]==x){
					for(int j=i;j<last;j++)
					{
						element[j]=element[j+1];
					}
					last--;
				}
				
			}
		}
		
		//Them vao xau x
		void insert(const string &x){
			int i,j;
			bool had;
			had=false;
			//Neu mang rong
			if(last==-1)
			{
			
				element=new string[1];
				element[0]=x;
				
				last=0;
				capacity=1;
				return;
			}
//			//Kiem tra co x khong
//			for(int i=0;i<last+1;i++)
//			{
//				if(element[i]==x){
//					had=true;
//					break;
//				}
//			}
//			//Neu khong co x
//			if(had==false){
//				if(last+1>=capacity){
//					capacity=2*capacity;
//					string *p=new string[capacity];
//					for(int i=0;i<last+1;i++)
//					{
//						p[i]=element[i];
//					}
//					last++;
//					p[last]=x;
//					delete element;
//					element=p;
//					
//				}
//				else{
//					element[last++]=x;
//				}	
//			}
//			return;
				
				
			
			
		}
		//Nap chong
		 StringSet& operator=(const StringSet& asset) {
            this->element = asset.element;
            this->capacity = asset.capacity;
            this->last = asset.last;
            return *this;
        }
        
        StringSet& operator+(const StringSet& asset) {
            for(int i = 0; i <= asset.last; i++) {
                if(find(asset.element[i]) == -1) {
                    insert(asset.element[i]);
                }
            }
            sort();
            return *this;
        }
		//sap xep mang
		void sort(){
			string temp;
			for(int i=0;i<last;i++)
			{
				for(int j=i+1;j<last+1;j++)
				{
					if(element[i]>element[j])
					{
						temp=element[i];
						element[i]=element[j];
						element[j]=temp;
					}
				}
			}
		}
		//In mang
		void print() {
            for(int i = 0; i <= last; i++) {
                cout << element[i] << "   ";
                cout<<endl;
            }
        
        }
		
};


int main(){
	StringSet str;
	str.insert("January");
//	str.insert("Febuary");
//	str.insert("March");
//	str.insert("April");
	str.print();
	
	return 0;
	
}

