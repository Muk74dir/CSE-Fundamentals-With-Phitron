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

    void DFS_PostOrder(node *temp)          // F(left) + F(right) + F(root)
    {
        if(temp == NULL)return;                 //root =  0
        else                                    //     1    2
        {                                       //    5    3 4
            DFS_PostOrder(temp->left);
            DFS_PostOrder(temp->right);         //ANSWER = 5, 1, 3, 4, 2, 0
            cout<<temp->id<<" ";
        }

    }

};

int main()
{
    BinaryTree bt;
    bt.buld_tree();
    bt.DFS_PostOrder(bt.root);

    return 0;
}
