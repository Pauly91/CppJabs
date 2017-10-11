#include <iostream>

using namespace std;


/*
Read up how to build a tree in cpp
*/



class tree
{
    struct Node{
        
            int keyVal;
            Node *right;
            Node *left;
        
        };
    Node *root;
public:
    tree()
    {
        root = NULL;
        cout<<"Node created"<<endl;
    }
    ~tree(){}

    void insert(int keyVal)
    {
        if(root == NULL)
        {            
            root = new Node;
            root->keyVal = keyVal;
            root->left = NULL;
            root->right = NULL;
            cout<<"Root Node"<<endl;
            cout<<"Value :"<<keyVal<<endl;
        }
        else
        {
            insert_P(root, keyVal);
        }
    }
    void printPreOrder()
    {
        preOrder(root);
    }
private:
    void preOrder(Node *node)// The input parameters should be const, look into const references.
    {
        if(node != NULL)
        {
            cout<<node->keyVal<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void insert_P(Node *node, const int &val)
    {

        if(val>node->keyVal)
        {
            cout<<"Travel Right"<<endl;
            if(node->right == NULL)
            {
                node->right = new Node;
                node = node->right;
                node->right = node->left = NULL;
                node->keyVal = val;
                cout<<"insert: "<<val<<endl;
            }
            else
            {
                insert_P(node->right, val);
            }        
        }
        else
        {
            cout<<"Travel Left"<<endl;
            if(node->left == NULL)
            {
                node->left = new Node;
                node = node->left;
                node->right = node->left = NULL;
                node->keyVal = val;
                cout<<"insert: "<<val<<endl;
            }
            else
            {
                insert_P(node->left, val);
            }  
        }
        
    }
};



class expressionParser
{
public:
    expressionParser()
    {

    }


private:
    
};



int main()
{
    tree t1;
    t1.insert(1);
    t1.insert(3);
    t1.insert(5);
    t1.insert(0);
    t1.insert(-1);
    t1.insert(6);
    t1.printPreOrder();
    return 0;

}