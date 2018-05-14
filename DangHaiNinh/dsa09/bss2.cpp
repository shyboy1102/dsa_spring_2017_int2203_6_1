#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    string data;
    Node* left ;
    Node* right;
    Node* parent;
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

    void erase(Node* point)
    {
        if (point->right == NULL && point->left == NULL)
        {
            if(point->parent==NULL)
            {
                root = NULL;
                return;
            }
            if (point->parent->left == point)
            {
                point->parent->left = NULL;
                delete point;
            }
            else
            {
                point->parent->right = NULL;
                delete point;
            }
            return;
        }

        if (point->right != NULL && point->right != NULL)
        {
            Node* point2 = leftMost(point->right);
            point->data = point2->data;
            if (point2->parent->left == point2)
            {
                point2->parent->left = NULL;
                delete point2;
            }
            else
            {
                point2->parent->right = NULL;
                delete point2;
            }
            return;
        }

        if (point->right != NULL)
        {
            point = point->right;
            return;
        }
        else
        {
            point = point->left;
            return;
        }
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
            Node* point = root;
            while (point != NULL)
            {
                if (point->data.compare(x) == 0)
                {
                    if(point->right != NULL)
                    {
                        Node* x = leftMost(point->right);
                        return x->data;
                    }
                    else
                    {
                        Node* y = point->parent;
                        while (y != NULL &&  point == y->right)
                        {
                            point = y;
                            y = y->parent;
                        }
                        return y->data;
                    }
                }
                if (x.compare(point->data) < 0)
                {
                    point = point->left;
                }
                else
                {
                    point = point->right;
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

    Node* leftMost(Node* point) const
    {
        while(point->left != NULL)
        {
            point = point->left;
        }
        return point;
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
