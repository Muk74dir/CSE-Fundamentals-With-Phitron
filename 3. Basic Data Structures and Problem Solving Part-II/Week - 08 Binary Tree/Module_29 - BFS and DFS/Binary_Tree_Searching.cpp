#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int id;
    int value;
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

    node* CreateNode(int id, int value)
    {
        node *newnode = new node;
        newnode->value = value;
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


    void Insertion(int id, int value)               //Insertion Using BFS
    {
        node *newnode = CreateNode(id, value);
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

    void Search(node *temp, int value)          //Search Using DFS
    {
        if(temp == NULL)return;
        if(temp->value == value)
            cout<<temp->id<<" ";
        Search(temp->left, value);
        Search(temp->right, value);
    }
};

int main()
{
    BinaryTree bt;
    bt.Insertion(0, 5);
    bt.Insertion(1, 10);
    bt.Insertion(2, 10);                        //       0
    bt.Insertion(3, 9);                         //    1    2
    bt.Insertion(4, 8);                         //   3 4  5 6
    bt.Insertion(5, 5);
    bt.Insertion(6, 7);
    bt.BFS();
    cout<<endl;cout<<endl;
    bt.Search(bt.root, 5);cout<<endl;
    bt.Search(bt.root, 10);cout<<endl;
    bt.Search(bt.root, 9);cout<<endl;

    return 0;
}
