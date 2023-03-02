#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int value;
    node* Left;
    node* Right;
};

class BST{
public:
    node *root;
    BST()
    {
        root = NULL;
    }

    node *CreatNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;
        return newnode;
    }

    void Insert(int value)
    {
        node *newnode = CreatNode(value);
        if(root == NULL){
            root = newnode;
            return;
        }
        node *cur = root;
        node *prev = NULL;

        while(cur != NULL){
            if(newnode->value > cur->value){
                prev = cur;
                cur = cur->Right;
            }
            else
            {
                prev = cur;
                cur = cur->Left;
            }
        }
        if(newnode->value > prev->value){
            prev->Right = newnode;
        }
        else
        {
            prev->Left = newnode;
        }

    }

    bool Search(int value)
    {
        node *temp = root;
        while(temp != NULL)
        {
            if(value > temp->value)
            {
                temp = temp->Right;
            }
            else if(value < temp->value)
            {
                temp = temp->Left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);
    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //1
    cout<<bst.Search(60)<<"\n"; //0
    return 0;
}

