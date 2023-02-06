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
    int sz =0;

    LinkedList()
    {
        head = NULL;
    }

    node *CreateNode(int value){
        sz++;
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
    void InsertAtHead(int value){
        node *a = CreateNode(value);
        if(head == NULL){
            head = a;
        }
        else{
            a->next = head;
            head = a;
        }
    }
    int getSize(){
        return sz;
    }
    void Traverse(){
        node *a = head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<endl;
    }
    void InsertAfterValue(int key, int value){
        node *a = head;
        while(a != NULL){
            if(a->data == key){
                break;
            }
            a = a->next;
        }
        if(a == NULL){
            cout<<key<<" VALUEDOESN'T EXIT"<<endl;
            return;
        }
        else{
            node *b = CreateNode(value);
            b->next = a->next;
            a->next = b;
        }
    }

};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.Traverse();
    cout<<l.getSize()<<endl;

    l.InsertAfterValue(30, 500);
    l.Traverse();
    cout<<l.getSize()<<endl;

    l.InsertAfterValue(5, 50);
    l.Traverse();
    cout<<l.getSize()<<endl;


    return 0;
}
