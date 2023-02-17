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

    void BFS()
    {
        if(root == NULL)return;
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


    void Insertion(int id)                          //Insertion Using BFS
    {
        node *newnode = CreateNode(id);
        if(root == NULL){
            root = newnode;
        }
        else
        {
            queue<node*>q;
            q.push(root);

            while(!q.empty())
            {
                node *temp = q.front();
                q.pop();

                if(temp->left != NULL){
                    q.push(temp->left);
                }

                else{
                    temp->left = newnode;
                    newnode->parent = temp;
                    return;
                }

                if(temp->right != NULL){
                    q.push(temp->right);
                }
                else{
                    temp->right = newnode;
                    newnode->parent = temp;
                    return;
                }
            }
        }
    }
};

int main()
{
    BinaryTree bt;
    bt.Insertion(0);
    bt.Insertion(1);
    bt.Insertion(2);
    bt.Insertion(3);
    bt.Insertion(4);
    bt.Insertion(5);
    bt.BFS();

    return 0;
}
