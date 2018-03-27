#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

struct DArrayList
{
public:
    DArrayList(); // Khoi tao danh sach rong
    DArrayList( const DArrayList & DS); // Ham kien tao sao chep (copy constructor)
    ~DArrayList(); // Ham huy (destructor)

    //void operator=(const DArrayList & DS); // Nap chong phep gan
    bool empty() const; // Kiem tra DS rong hay khong
    int length() const; // Xac dinh do dai DS
    void insert(int index, const int value); // Xen gia tri x vao vi tri i trong DS
    void append(const int value); // Them x vao duoi DS
    void erase(int index); // Loai khoi DS phan tu o vi tri i
    int& at(int index); // Tra ve tham chieu toi phan tu o vi tri i
    void print() const; // In ra man hinh toan bo DS
private:
    int * element; // Mang dong element luu toan bo DS
    int last; // chi so cua phan tu cuoi cung
    int size; // kich thuoc (so phan tu toi da) cua mang element
};

// 1. Ham khoi tao danh sach rongs
DArrayList::DArrayList(){
    element=NULL;
    size=0;
    last=-1;
}
DArrayList::~DArrayList(){
    delete element;
}

DArrayList::DArrayList( const DArrayList & DS){
    last=DS.last;
    size = DS.size;
    for(int i=0;i<=last;i++) 
		element[i]=DS.element[i];
            
}


// 4. Ham kiem tra danh sach co rong khong
bool DArrayList::empty() const
{
    return element == NULL;
}

// 5. Ham xac dinh do dai danh sach
int DArrayList::length() const
{
    return last + 1;
}

// 6. Ham chen gia tri value vao vi tri index trong danh sach
void DArrayList::insert(int index, const int value)
{
	if(index < 0 || index > last+1)
		cout << "\nTrong danh sach khong co vi tri nay.";
    else if(last+1==size){
        size=2*size+1;
        int *p=new int[size];
        for(int j = 0; j < index; j++) p[j] = element[j];
        p[index] = value;
        last++;
        for(int j = index + 1; j <= last; j++) p[j] = element[j-1];
        delete[] element;
        element = p;
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
	}
}
// 7. Ham chen gia tri value vao cuoi danh sach
void DArrayList::append(const int value)
{
	last++;
	element[last] = value;
	size++;
}

// 8. Ham loai khoi danh sach phan tu o vi tri index
void DArrayList::erase(int index)
{
     if(index < 0 || index > last) 
	 	cout<<"\nTrong danh sach khong co phan tu co chi so nay.";
    else {
        for(int j = index; j < last; j++) 
			element[j] = element[j+1];
        last = last - 1;
    }
} 
// 9. Ham tra ve tham chieu toi phan tu o vi tri index
int& DArrayList::at(int index)
{
    assert(last >= 0 && index <= last && index >= 0);
    return element[index];
}

// 10. Ham in ra man hinh toan bo danh sach
void DArrayList::print() const
{
    for(int i = 0; i < last+1; i++){
    	cout << element[i];
	}
}

void testappend(DArrayList & someList, const int value)
{
    cout << "Danh sach truoc khi append " << value << endl;
    someList.print(); cout << endl;
    someList.append(value);
    cout << "Danh sach sau khi append " << value << endl;
    someList.print(); cout << endl << endl;
}

void testinsert(DArrayList & someList, int index, const int value)
{
    cout << "Danh sach truoc khi insert " << value << " vao vi tri " << index << endl;
    someList.print(); cout << endl;
    someList.insert(index, value);
    cout << "Danh sach sau khi insert " << value << " vao vi tri " << index << endl;
    someList.print(); cout << endl << endl;
}

void testerase(DArrayList & someList, int index)
{
    cout << "Danh sach truoc khi erase tai vi tri " << index << endl;
    someList.print(); cout << endl;
    someList.erase(index);
    cout << "Danh sach sau khi erase tai vi tri " << index << endl;
    someList.print(); cout << endl << endl;
}

int main()
{
    
    DArrayList L1; L1.print(); cout << endl;
    testinsert(L1, 0, 2);

   
    testappend(L1, 3);
    testappend(L1, 4);
    testappend(L1, 5);
    testinsert(L1, 0, 2);
    testinsert(L1, 0, 1);
    testinsert(L1, 2, 3);
    cout << "L1.at(3): " << L1.at(3) << endl;
    L1.print(); cout << endl;

	cout << endl;

    return 0;
}
