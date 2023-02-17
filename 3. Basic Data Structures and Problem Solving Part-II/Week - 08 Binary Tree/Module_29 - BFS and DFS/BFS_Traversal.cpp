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

    void BFS()
    {
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();

            int p=-1, l=-1, r=-1;
            if(temp->parent != NULL){
                p = temp->parent->id;
            }
            if(temp->left != NULL){
                l = temp->left->id;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                r = temp->right->id;
                q.push(temp->right);
            }
            cout<<"NODE ID= "<<temp->id<<" Parent ID = "<<p<<" Left Child : "<<l<<" Right Child : "<<r<<endl;
        }
    }

};

int main()
{
    BinaryTree bt;
    bt.buld_tree();
    bt.BFS();

    return 0;
}
