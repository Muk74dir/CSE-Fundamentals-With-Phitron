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
         node *allnode[6];
         for(int i=0; i<6; i++)
             allnode[i] = CreateNode(i);


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

    void DFS_PreOrder(node *temp)         // F(root) + F(left) + F(right)
    {
        if(temp == NULL)return;                 //root =  0
        else                                    //     1    2
        {                                       //    5    3 4
            cout<<temp->id<<" ";
            DFS_PreOrder(temp->left);
            DFS_PreOrder(temp->right);          //ANSWER = 0, 1, 5, 2, 3, 4
        }

    }

};

int main()
{
    BinaryTree bt;
    bt.buld_tree();
    bt.DFS_PreOrder(bt.root);

    return 0;
}
