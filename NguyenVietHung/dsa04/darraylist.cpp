#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

struct DArrayList {
	private:
    	int *element;
    	int last,size;
    public:
    // khoi tao danh sach rong
    	DArrayList() {
    		element=NULL;
    		size=0;
    		last=-1;
		}
    // ham sao chep 
    	DArrayList( const DArrayList & DS){
    		last=DS.last;
    		size = DS.size;
    		for(int i=0;i<=last;i++) 
				element[i]=DS.element[i];
		}
    // ham xoa
		~DArrayList(){
    		delete element;
    	}
	// kiem tra danh sach rong
		bool empty() const {
            return element == NULL;
        }
    // do dai cua danh sach
    	int getsize() const {
            return last+1;
        }
    // ham insert
    	int insert(int index, const int value) {
			if(index < 0 || index > last){
			
				cout << "\nVi tri nay khong co trong danh sach.\n";
				return 0;
			}
    		else {
				if(last+1==size){
        			size=2*size+1;
        			int *p=new int[size];
        			for(int j = 0; j < index; j++) p[j] = element[j];
        			p[index] = value;
        			last++;
        			for(int j = index + 1; j <= last; j++) p[j] = element[j-1];
        			delete[] element;
        			element = p;
        			return 1;
        		}
				else {
					int *p = new int[size];
        			for(int j = 0; j < index; j++) 
					p[j]=element[j];
        			p[index] = value;
        			last++;
        			for(int j = index + 1; j <= last; j++) 
					p[j] = element[j-1];
        			delete[] element;
        			element = p;
        			return 1;
        		}
        	}
        }
    // chen vao cuoi danh sach
    	void append(const int x) {
    		if(last+1 < size){
				element[last+1]=x;
				last++;
			}
			else
			{
				size=2*size+1;
                int *p=new int[size];
                for(int i=0;i<=last;i++) p[i]=element[i];
                last++;
                p[last]=x;
                delete[] element;
                element=p;
			}
		}
    // ham xoa 1 phan tu trong danh sach
		int erase(int index) {
     		if(index < 0 || index > last) {
				cout<<"\nTrong danh sach khong co phan tu co chi so nay.\n";
				return 0;
			}
    		else {
        		for(int j = index; j < last; j++) 
				element[j] = element[j+1];
        		last = last - 1;
        		return 1;
        	}
        }
	// tra ve gia tri tham chieu
    	int& at(int index) {
    		assert(last >= 0 && index <= last && index >= 0);
    		return element[index];
    	}
    // ham in danh sach
    	void print() const {
    		for(int i = 0; i < last+1; i++){
    		cout << element[i]<<", ";
			}
			cout <<endl;
		};
};
    
int main() {
	DArrayList A;
	A.append(1);
	A.append(3);
	A.append(7);
	A.append(2);
	A.append(14);
	A.append(45);
	A.append(9);
	A.append(11);
	A.print();
	cout <<endl;
	cout << "empty(A) = ";
	cout << (A.empty()? "true":"false") << endl;
	cout << "length(A) = " << A.getsize() << endl;
	cout << "element(A, 0) = " << A.at(0) << endl;
	
	cout << "insert(A,2,10) : ";
	if(A.insert(10, 2)){
		A.print();
}
	
	cout << "append(-5) = ";
	A.append(-5);
	A.print();
	
	
	cout << "erase(A, 3) : ";
	if(A.erase(3)){
		 
		A.print();
	}
	return 0;
}

	
