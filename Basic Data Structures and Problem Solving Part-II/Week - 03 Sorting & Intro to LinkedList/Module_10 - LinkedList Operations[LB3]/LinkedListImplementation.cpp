#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
};


class LinkedList{
public:
    node *head;

    LinkedList()
    {
        head = NULL;
    }

    // create a new node where data = x & next = NULL;
    node* CreateNewNode(int x){
        node *newnode = new node;
        newnode->data = x;
        newnode->next = NULL;

        return newnode;
    }
    //insert new value at Head
    void InsertAtHead(int x){
        node *a = CreateNewNode(x);
        if(head == NULL){
            head = a;
            return;
        }
        a->next = head;
        head = a;
    }

    void Traverse(){
        node *a = head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<"\n";
    }

    void SearchDistinctValue(){
    }

    void SearchAllValue(){
    }
};


int main()
{
    LinkedList ll;

    ll.Traverse();
    ll.InsertAtHead(10);
    ll.Traverse();
    ll.InsertAtHead(30);
    ll.Traverse();
    ll.InsertAtHead(40);
    ll.Traverse();


}

