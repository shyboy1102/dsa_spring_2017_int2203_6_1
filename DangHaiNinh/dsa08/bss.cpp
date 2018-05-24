#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    string data;
    Node* left ;
    Node* right;
};

class BtsStringSet
{
public:
    BtsStringSet()
    {
        root = NULL;
    }

    ~BtsStringSet()
    {
        delete root;
    }

    BtsStringSet(char* filename):root(NULL)
    {
        ifstream file;
        file.open(filename);
        if(file.is_open())
        {
            while(!file.eof())
            {
                string alt;
                file >> alt;
                insert(alt);
            }
        }
        file.close();
    }

    bool find(const string & x)
    {
        Node *point = root;
        while (point != NULL)
        {
            if (x.compare(point->data) == 0)
            {
                return true;
            }
            else
            {
                if (x.compare(point->data) < 0)
                {
                    point = point->left;
                }
                else
                {
                    point = point->right;
                }
            }
        }
    }

    void insert(const string & x){
        Node * point;
        Node * branchNode;
        branchNode = NULL;
        point = root;

        while (point != NULL)
        {
        //Kiem tra x da ton tai chua
            branchNode = point;
            if (x.compare(point->data) == 0)
            {
                break;
            }
            else
            {
                if(x.compare(point->data) < 0)
                {
                    point = point->left;
                }
                else
                {
                    point = point->right;
                }
            }
        }
        //Insert x
        if (point == NULL)
        {
            Node * newNode = new Node();
            newNode->data = x;
            newNode->left = NULL;
            newNode->right = NULL;
            if(root == NULL)
            {
                root = newNode;
            }
            else
            {
                if (x.compare(branchNode->data) < 0)
                {
                    branchNode->left = newNode;
                }
                else
                {
                    branchNode->right = newNode;
                }
            }
        }
    }

    void erase(const string &x)
    {
        Node *point;
        Node *branchNode;
        Node *child;
        branchNode = NULL;
        point = root;
        //Kiem tra co ton tai ko
        while(point != NULL)
        {
            if (x.compare(point->data) == 0)
            {
                break;
            }
            branchNode = point;
            if (x.compare(point->data) < 0)
            {
                point = point->left;
            }
            else
            {
                point = point->right;
            }
        }
        if (point == NULL)
        {
            cout <<"No string x to erase " << x << endl;
            return;
        }
        //Xoa x
        if (point->left != NULL && point->right != NULL)
        {
            Node *alt = point;
            branchNode = point;
            point = point->left;
            while (point->right != NULL)
            {
                branchNode = point;
                point = point->right;
            }
            alt->data = point->data;
            delete point;
        }
        if (point->left != NULL)
        {
            child = point->left;
        }
        else
        {
            child = point->right;
        }
        if (point == root)
        {
            root = child;
        }
        else
        {
            if (branchNode->left == point)
            {
                branchNode->left = child;
            }
            if (branchNode->right == point)
            {
                branchNode->right = child;
            }

        }
        delete point;
    }

    string min() const
    {
        Node *point = root;
        Node *minNode;
        if (root == NULL)
        {
            return "Empty Tree";
        }
        else
        {
            while(point != NULL)
            {
                minNode = point;
                point = point->left;
            }
            return minNode->data;
        }
    }

    string max() const
    {
        Node *point = root;
        Node *maxNode;
        if (root == NULL)
        {
            return "Empty Tree";
        }
        else
        {
            while(point != NULL)
            {
                maxNode = point;
                point = point->right;
            }
            return maxNode->data;
        }
    }

    string predecessor(const string & x) const
    {
        if (root == NULL)
        {
            return "Empty Tree";
        }
        else
        {
            Node *point = root;
            string result = "No string x";
            while (point != NULL)
            {
                if (x.compare(point->data) < 0)
                {
                    point = point->left;
                }
                else if (x.compare(point->data) > 0)
                {
                    result = point->data;
                    point = point->right;
                }
                else
                {
                    if (point->left != NULL)
                    {
                        return point->left->data;
                    }
                    if (point->left == NULL)
                    {
                        return result;
                    }
                }
            }
            return "No string before x in tree";
        }
    }

    string successor(const string & x) const
    {
        if (root == NULL)
        {
            return "Empty Tree";
        }
        else
        {
            Node *point = root;
            string result = "No string x";
            while (point != NULL)
            {
                if (x.compare(point->data) < 0)
                {
                    result = point->data;
                    point = point->left;
                }
                else if (x.compare(point->data) > 0)
                {
                    point = point->right;
                }
                else
                {
                    if (point->right == NULL)
                    {
                        return result;
                    }
                    if (point->right != NULL)
                    {
                        return point->right->data;
                    }
                }
            }
            return "No string after x in tree";
        }
    }

    void visit(Node* alt) const
    {
        if(alt == NULL)
        {
            return;
        }
        cout << "\t\t" << alt->data << endl;
        visit(alt->left);
        visit(alt->right);
    }

    void printInorder() const
    {
        visit(root);
    }

private:
    Node* root;
};

int main(){
    BtsStringSet readFile("file.txt");
    BtsStringSet demo;

    demo.insert("a");
    demo.insert("b");
    demo.insert("c");
    demo.insert("d");
    demo.insert("e");

    cout<<"\n\tBtsStringSet demo:" << endl;
    demo.printInorder();

    cout << "\n\tdemo.min() -> " << demo.min() << endl;
    cout << "\n\tdemo.max() -> " << demo.max() << endl;
    cout << "\n\tdemo.predecessor(a) -> " << demo.predecessor("a") << endl;
    cout << "\n\tdemo.successor(a) -> " << demo.successor("a") << endl;
    cout << "\n\tdemo.find(a) -> ";
    if (demo.find("a") == 1)
        cout << "Found ""a"" "<< endl;
    else
        cout << "Not found ""a"" " << endl;

    cout << "\n\tdemo.erase(""e""):" << endl;
    demo.erase("e");
    demo.printInorder();
}
