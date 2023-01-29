#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;
};

class DoublyLL{
public:
    node *head;
    int sz;

    DoublyLL()
    {
        head = NULL;
        sz = 0;
    }

    int getSize(){
        return sz;
    }

    node *CreateNewNode(int data){
        sz++;
        node *newnode = new node;              //O(1)
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }


    void InsertAtHead(int data){
        node *a = CreateNewNode(data);
        if(head == NULL){                   //O(1)
            head = a;
        }
        else{
            head->prev = a;
            a->next = head;
            head = a;
        }
    }

    void Traverse(){
        node *a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<endl;
    }

    void Reverse(){
        if(head == NULL)return;
        node *a = head;
        int crntind = 0;
        while(crntind != sz-1){     //O(n)
            a = a->next;
            crntind++;
        }
        node *b = head;
        while(b != NULL){
            swap(b->next, b->prev);
            b = b->prev;
        }
        head = a;
    }

};

int main()
{
    DoublyLL dl;
    dl.InsertAtHead(10);
    dl.InsertAtHead(20);
    dl.InsertAtHead(30);
    dl.Traverse();
    cout<<"SIZE : "<<dl.getSize()<<endl;

    cout<<"Reverse Print : "<<endl;
    dl.Reverse();
    dl.Traverse();
    return 0;
}
