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

    void SearchAllValue(){
        node *a = head;
        int idx = 0;
        while(a!=NULL){
            cout<<a->data<<" is found at index : "<<idx;
            cout<<endl;
            a = a->next;
            idx++;
        }
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

    void printReverse(){
        node *a = head;
        while(a != NULL){
            printReverse();
            cout<<a->data<<" ";
            a = a->next;
        }
    }


    void swapFirst(){

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

