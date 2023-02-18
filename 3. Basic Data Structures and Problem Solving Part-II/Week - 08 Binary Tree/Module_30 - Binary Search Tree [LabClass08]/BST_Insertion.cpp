#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int value;
    node *left;
    node *right;
};

class BST{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node *CreateNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

     void BFS()
     {
         if(root == NULL)return;
         queue<node*>q;
         q.push(root);
         while (!q.empty())
         {
             node *temp = q.front();
             q.pop();

            int p=-1, l=-1, r=-1;
            if(temp->left != NULL){
                l = temp->left->value;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                r = temp->right->value;
                q.push(temp->right);
            }
            cout<<"NODE value = "<<temp->value<<" Left Child : "<<l;
            cout<<" Right Child : "<<r<<"\n";
         }
     }

     void Insert(int value)
     {
        node *newnode = CreateNode(value);
        if(root == NULL){root = newnode;return;}
        else
        {
            node *prev = NULL;
            node *cur = root;

            while(cur != NULL)
            {
                if(newnode->value > cur->value ){
                    prev = cur;
                    cur = cur->right;
                }
                else
                {
                    prev = cur;
                    cur = cur->left;
                }
            }
            if(prev->value > newnode->value){
                prev->left = newnode;
            }
            else
            {
                prev->right = newnode;
            }
        }

     }
};


int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);
    bst.BFS();

}
