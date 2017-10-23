#include <iostream>

using namespace std;


/*
Read up how to build a tree in cpp and add the rest of the functionality for tree
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
    ~tree()
    {
        // Go around a delallocate memory ?
        cout<<"Tree Deleted"<<endl;
    }

    void del(int keyVal)
    {
        if(root == NULL)
        {  
            cout<<"Tree is empty"<<endl;
            return;
        }
        else
        {
            Node *node = delete_P(root, keyVal);
            if(node == NULL)
            {
                cout<<"The Node does not exist"<<endl;
            }
        }
    }
   
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
    void search(const int keyVal)
    {
        Node *node = search_P(root, keyVal);
        if(node != NULL)
        {
            cout<<"Node exist"<<endl;
        } 
        else
        {
            cout<<"Node is not present"<<endl;
        }
    }


    void printPreOrder()
    {
        preOrder(root);
    }
    void printInOrder()
    {
        inOrder(root);
    }
 ///////////////////////////////////////////////////////////////////////////////
 //==========================================================================//   
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
    void inOrder(Node *node)
    {
        if(node != NULL)
        {
            preOrder(node->left);
            cout<<node->keyVal<<endl;
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
    Node* search_P(Node *node,const int keyVal)
    {
        
        /*
         Make this with a while loop
         -  This will be usefull to get the previous node for deletion of
            nodes with 1 child.
         */
        
        
        if(node == NULL)
        {
            return node;
        }
        else if(node->keyVal > keyVal)
        {
            cout<<"val:"<<node->keyVal<<endl;
            return search_P(node->left,keyVal);
        }
        else if(node->keyVal < keyVal)
        {
            cout<<"val:"<<node->keyVal<<endl;
            return search_P(node->right,keyVal);
        }
        else
        {
            return node;
        }
    }
/*
    void del_P(Node *node,const int keyVal)
    {

        //
        Refer these:
          - https://helloacm.com/how-to-delete-a-node-from-a-binary-search-tree/
          - http://www.algolist.net/Data_structures/Binary_search_tree/Removal  
        //
        //Node *node = search_P(node,keyVal);       

    }
*/
    Node* searchMin(Node *node)
    {
        while(node->left != NULL)
        {
            node = node->left;
        }    
        return node;
    }
    Node* delete_P(Node* node, const int keyVal)
    {
        cout<<"Searching For:"<<keyVal<<endl;
        Node *previousNode = NULL;
        while(node != NULL)
        {

            if(node->keyVal == keyVal)
            {
                break;
            }
            else if(node->keyVal > keyVal)
            {
                previousNode = node;
                node = node->left; 
            }
            else
            {
                previousNode = node;
                node = node->right;  
            }
        
        }
        if(node == NULL)
        {
            return NULL;
        }
        if(node->right == NULL && node ->left == NULL)
        {
            if(previousNode->keyVal > node->keyVal)
            {
                previousNode->left = NULL;
            }
            else
            {
                previousNode->right = NULL;
            }
            delete node;
        }
        else if(node->right == NULL && node->left != NULL)
        {
            if(previousNode->right == node)
            {
                previousNode->right = node->left;
            }
            else
            {
                previousNode->left = node->left;
            }
            delete node;
        }
        else if(node->right != NULL && node->left == NULL)
        {
            if(previousNode->right == node)
            {
                previousNode->right = node->right;
            }
            else
            {
                previousNode->left = node->right;
            }
            delete node;
        }
        else if(node->right != NULL && node->left != NULL)
        {
            Node *minNode = searchMin(node->right);
            cout<<"Min Node: "<<minNode->keyVal<<endl;
            node->keyVal = minNode->keyVal;
            delete minNode;
        }
        return node;
    }
};



/*

Read about expression trees, implementation and about inheritence. So inherit from tree class.

*/






int main()
{
    tree t1;
    t1.insert(1);
    t1.insert(3);
    t1.insert(5);
    t1.insert(0);
    t1.insert(-1);
    t1.insert(2);
    cout<<endl<<endl;
    //t1.printPreOrder();
    t1.printPreOrder();
    t1.search(5);
    //t1.search(9);
    t1.del(3);
    t1.printPreOrder();
    t1.del(0);
    t1.printPreOrder();
    t1.del(2);
    t1.printPreOrder();
    t1.del(2);
    t1.printPreOrder();
    return 0;


    
}
/*
               1
            /    \
         0        3
        /       /   \
      -1       5      5    
                     
                     

*/