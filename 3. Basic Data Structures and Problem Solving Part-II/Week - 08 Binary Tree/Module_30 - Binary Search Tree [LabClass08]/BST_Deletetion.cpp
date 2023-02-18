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
            if(temp->left != NULL)
            {
                l = temp->left->value;
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
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
        if(root == NULL)
        {
            root = newnode;
            return;
        }
        else
        {
            node *prev = NULL;
            node *cur = root;

            while(cur != NULL)
            {
                if(newnode->value > cur->value)
                {
                    prev = cur;
                    cur = cur->right;
                }
                else
                {
                    prev = cur;
                    cur = cur->left;
                }
            }

            if(prev->value > newnode->value)
                prev->left = newnode;
            else
                prev->right = newnode;
        }

    }

    void Delete(int value)
    {
        node *prev = NULL;
        node *cur = root;
        while(cur != NULL)
        {
            if(value > cur->value){
                prev = cur;
                cur = cur->right;
            }

            else if(value < cur->value){
                prev = cur;
                cur = cur->left;
            }

            else break;
        }
        if(cur == NULL){
            cout<<"Value Not Found"<<endl;
            return;
        }

        // CASE 1: NO Child, Both Child of a node is NULL
        if(cur->left == NULL && cur->right == NULL)
        {
            if(prev->left != NULL && prev->left->value == cur->value)
                prev->left = NULL;
            else
                prev->right = NULL;
            delete cur;
            return;
        }
        ////////////////////////////////////////

        //CASE 2: Node has only one (left/right) child
        if(cur->left != NULL && cur->right == NULL){
            if(prev->left != NULL && prev->left->value == cur->value)
                prev->left = cur->left;
            else
                prev->right = cur->left;
            delete cur;
            return;
        }

        if(cur->left == NULL && cur->right != NULL){
            if(prev->left != NULL && prev->right->value == cur->value)
                prev->right = cur->right;
            else
                prev->left = cur->right;
            delete cur;
            return;
        }
        ////////////////////////////////////////

        //CASE 3: Node has both child
        node *temp = cur->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        int saved = temp->value;
        Delete(saved);
        cur->value = saved;

    }
};


int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);                      //        6
    bst.Insert(3);                      //    4        7
    bst.Insert(5);                      //   3  5        8
    bst.Insert(7);
    bst.Insert(8);
    bst.BFS();
    cout<<endl;

    //CASE 1: NO Child
    bst.Delete(5);
    bst.BFS();
    cout<<endl;

    //CASE 2: Only One Child
    bst.Delete(4);
    bst.BFS();
    cout<<endl;

    //CASE 3: Only One Child
    bst.Delete(6);
    bst.BFS();
    cout<<endl;





}
