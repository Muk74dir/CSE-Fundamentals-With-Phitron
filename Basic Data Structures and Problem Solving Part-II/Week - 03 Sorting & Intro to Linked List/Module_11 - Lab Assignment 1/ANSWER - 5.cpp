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
    node* CreateNewNode(int x){
        node *newnode = new node;
        newnode->data = x;
        newnode->next = NULL;

        return newnode;
    }
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
        cout<<endl;
    }
    int getValue(int x){
        node *a = head;
        int idx = 0;
        while(a!=NULL){
            if(idx == x){
                return a->data;
            }
            a = a->next;
            idx++;
        }
        return -1;
    }
    int getSize(){
        int cnt=0;
        node *a = head;
        while(a!=NULL){
            cnt++;
            a = a->next;
        }
        return cnt;
    }
    void areverse(node* a){
        if (a == NULL) return;
        areverse(a->next);
        cout<<a->data<<" ";
    }
    void printReverse(){
        node *a = head;
        areverse(a);
        cout<<"\n";
    }
    void swapFirst(){
        node *a = head;
        head = a->next;
        a->next = head->next;
        head->next = a;
    }


};


int main()
{
    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    cout<<l.getValue(2)<<"\n";
    cout<<l.getValue(6)<<"\n";
    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse();

}

