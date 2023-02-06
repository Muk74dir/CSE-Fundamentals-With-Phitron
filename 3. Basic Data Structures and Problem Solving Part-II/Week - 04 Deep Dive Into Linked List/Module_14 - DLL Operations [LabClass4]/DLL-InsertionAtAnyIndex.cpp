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

    void Insert(int index, int data){
        if(index == 0){
            InsertAtHead(data);             // O(n)
            return;
        }

        if(index > getSize()){
            return;
        }
        node *temp = head;
        int crntindx = 0;
        while(crntindx != index-1){
            temp = temp->next;
            crntindx++;
        }
        node *newnode = CreateNewNode(data);
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
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

    dl.Insert(0, 500);
    dl.Traverse();
    cout<<"SIZE : "<<dl.getSize()<<endl;
    return 0;
}
