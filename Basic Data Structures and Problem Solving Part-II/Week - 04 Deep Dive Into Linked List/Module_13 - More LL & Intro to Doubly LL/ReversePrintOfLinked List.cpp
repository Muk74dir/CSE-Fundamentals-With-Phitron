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

    void ReversePrinter(node *head){
        if(head==NULL)return;              //Base Case of Recursion
        ReversePrinter(head->next);
        cout<<head->data<<" ";
    }
    void ReversePrint(){
        ReversePrinter(head);
        cout<<endl;
    }


};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(40);
    l.InsertAtHead(50);
    l.InsertAtHead(60);
    l.Traverse();
    cout<<"SIZE : "<<l.getSize()<<endl;

    cout<<"Printing Reversely : "<<endl;
    l.ReversePrint();

    return 0;
}
