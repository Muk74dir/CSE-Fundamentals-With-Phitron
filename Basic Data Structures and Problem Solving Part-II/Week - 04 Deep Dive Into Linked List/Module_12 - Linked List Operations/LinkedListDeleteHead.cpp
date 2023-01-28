#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};
class LinkedList{
public:
    node *head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz = 0;
    }
    node* CreateNewNode(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void InsertAtHead(int value){
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL){
            head = a;
        }
        else{
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
        cout<<"\n";
    }

    int getSize(){
        return sz;
    }

    void DeleteAtHead(){
        if(head == NULL){
            return;
        }
        else{
            sz--;
            node *a = head;
            head = a->next;
            delete a;
        }
    }
};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.InsertAtHead(50);

    cout<<l.getSize()<<endl;
    l.Traverse();
    l.DeleteAtHead();
    l.Traverse();
    cout<<l.getSize()<<endl;
}
