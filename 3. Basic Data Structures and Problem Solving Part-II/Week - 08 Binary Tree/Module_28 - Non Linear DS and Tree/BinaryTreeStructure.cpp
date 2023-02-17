#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int id;
    node *parent;
    node *left;
    node *right;
};

class BinaryTree{
public:
    node *root;
    node *allnode[6];

    BinaryTree()
    {
        root = NULL;
    }

    node* CreateNode(int id)
    {
        node *newnode = new node;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->id = id;
        return newnode;
    }

    void buld_tree()
    {
         for(int i=0; i<6; i++)
         {
             allnode[i] = CreateNode(i);
         }
         allnode[0]->left = allnode[1];
         allnode[0]->right = allnode[2];

         allnode[1]->left = allnode[5];
         allnode[1]->parent = allnode[0];

         allnode[2]->left = allnode[3];
         allnode[2]->right = allnode[4];
         allnode[2]->parent = allnode[0];

         allnode[5]->parent = allnode[1];
         allnode[3]->parent = allnode[2];
         allnode[4]->parent = allnode[2];

         root = allnode[0];
    }
    void print_tree()
    {
        for(int j=0; j<4; j++)
        {
            int p=-1, l=-1, r=-1;
            if(allnode[j]->parent != NULL)
                p = allnode[j]->parent->id;
            if(allnode[j]->left != NULL)
                l = allnode[j]->left->id;
            if(allnode[j]->right != NULL)
                r = allnode[j]->right->id;

            cout<<"NODE = "<<j<<"-->Parent : "<<p<<" Left Child : "<<l<<" Right Child : "<<r<<endl;
        }

    }
};

int main()
{
    BinaryTree bt;
    bt.buld_tree();
    bt.print_tree();

    return 0;
}
