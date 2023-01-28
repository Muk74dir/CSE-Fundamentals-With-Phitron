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
    void DeleteAtAnyIndex(int idx){
        if(idx<0 || idx>sz-1)return;
        if(head == NULL){
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int crntinx = 0;
        while(crntinx !=idx-1){
            a = a->next;
            crntinx++;
        }
        node *b = a->next;
        a->next = b->next;
        delete b;
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


    l.Traverse();
    cout<<l.getSize()<<endl;

    l.DeleteAtAnyIndex(2);
    l.Traverse();
    cout<<l.getSize()<<endl;

    return 0;
}
