#include <iostream>
#include <list>
using namespace std;

/* Class represents list of intergers setup by array */
class DArrayList
{
public:
    /* Initialization of the empty list */
    ArrayList();

    /* List properties */
    int size;
    int *element = new int[size];
    int current;

    /* Functions */
    const DArrayList& operator=(const DArrayList &list)
    {
        this->size = list.size;
        for(int i = 0; i < size; i++) 
        {
            *(this->element + i) = *(list.element + i);
        }
        return *this;
    }
    bool empty() const;
    void insert(const int x, int i);
    void append(const int x);
    void erase(int i);
    int& at(int i) const;
    void print() const;
    void listDel();
};

int main()
{
    /* Creat list A */
    DArrayList A;
    for (int i = 1; i < 4; i++)
    {
        A.append(i);
    }
    for (int i = 3; i < 6; i++)
    {
        A.append(i);
    }
    cout << "\n\tA = ";
    A.print();
    cout << endl;


    /* empty */
    if (A.empty())
    {
        cout << "\n\tempty(A) -> true" << endl;
    }
    else
    {
        cout << "\n\tempty(A) -> false" << endl;
    }

    /* length */
    cout << "\n\tlength(A) -> ";
    cout << A.size << endl;

    /* element */
    cout << "\n\telement(A, 0) -> ";
    cout << A.at(0) << endl;
    cout << "\telement(A, 2) -> ";
    cout << A.at(2) << endl;

    /* insert */
    cout << "\n\tinsert(A, 2, 10) -> ";
    A.insert(10, 2);
    A.print();
    cout << endl;

    /* del */
    cout << "\n\tdel(A, 3) = ";
    A.erase(3);
    A.print();
    cout << endl;

    /* Delete list */
    cout << "\n\tlistDel(A) -> ";
    A.listDel();
    cout << "A = ";
    A.print();
    cout << endl;

    return 0;
}

DArrayList::ArrayList()
{
    size = 0;
    current =  0;
}

/*!
 * Function: {bool} empty() const
 * @brief:
 *          <check list created at ArrayList() empty or not>.
 *
 * @param:
 *          <none>.
 *
 * @return:
 *          < true if list empty
 *            false if list not empty >.
 */
bool DArrayList::empty() const
{
    return size == 0? true : false;
}

/*!
 * Function: {void} insert(const int x, int i)
 * @brief:
 *          <insert element to list created at ArrayList()>.
 *
 * @param:
 *          <- x: value of element
 *           - i: the position in front of the added element >.
 *
 * @return:
 *          <none>.
 */
void DArrayList::insert(const int x, int i)
{
    size++;
    int *tmp = new int[size];
    for (int j = 0; j < i; j++)
    {
        *(tmp + j) = *(element + j);

    }
    *(tmp + i) = x;
    for(int j = i + 1; j < size; j++)
    {
        *(tmp + j) = *(element + (j - 1));
    }
    delete[] element;
    element = tmp;
//     for (int j = size - 1; j > i; j--)
//     {
//         *(element + j) = *(element + (j - 1));
//     }
//     *(element + i) = x;
}


/*!
 * Function: {void} append(const int x)
 * @brief:
 *          <insert element to the end of list created at ArrayList()>.
 *
 * @param:
 *          <x: value of element>.
 *
 * @return:
 *          <none>.
 */
void DArrayList::append(const int x)
{
    size++;
    *(element + (size - 1)) = x;
}

/*!
 * Function: {void} printList()
 * @brief:
 *          <print list to display>.
 *
 * @param:
 *          <none>.
 *
 * @return:
 *          <none>.
 */
void DArrayList::print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << *(element + i);
        cout << " ";
    }
}

/*!
 * Function: {int&} at(int i) const
 * @brief:
 *          <returns a reference to the element>.
 *
 * @param:
 *          <i: the position of the element>.
 *
 * @return:
 *          <reference to the element>.
 */
int& DArrayList::at(int i) const
{
    int tmp;
    tmp = *(element + i);
    return tmp;
}

/*!
 * Function: {void} erase(int i)
 * @brief:
 *          <delete element of list created at ArrayList()>.
 *
 * @param:
 *          <i: the position of element>.
 *
 * @return:
 *          <none>.
 */
void DArrayList::erase(int i)
{
    for (int j = i; j < size; j++)
    {
        *(element + j) = *(element + (j + 1));
    }
    size--;
}

void DArrayList::listDel()
{
    delete[] element;
    size = 0;
}