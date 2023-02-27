#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;
};

class DLL{
public:
    node *head;
    node *tail;
    int sz;

    DLL()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNode(int value)
    {
        sz++;
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void insertHead(int value)
    {
        node *temp = CreateNode(value);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertTail(int value)
    {
        node *temp = CreateNode(value);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void insertMid(int value)
    {
        if(sz < 2){
            insertTail(value);
            return;
        }
        int ind = 0;
        node *temp = head;
        while(ind < (sz/2)-1){
            ind++;
            temp = temp->next;
        }

        node *newnode = CreateNode(value);
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;

    }

    void print()
    {
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void merge(DLL temp)
    {
        tail->next = temp.head;
        temp.head->prev = tail;
    }
};

int main()
{
    DLL dl;
    dl.insertHead(5);
    dl.insertHead(5);
    dl.insertHead(5);
    dl.insertTail(3);
    dl.insertTail(8);
    dl.insertTail(9);
    dl.insertMid(1000);
    dl.print();

    DLL dl2;
    dl2.insertHead(50);
    dl2.insertHead(50);
    dl2.insertHead(50);
    dl2.insertTail(30);
    dl2.insertTail(80);
    dl2.insertTail(90);
    dl2.insertMid(9999);
    dl2.print();

    dl.merge(dl2);
    dl.print();

    return 0;
}
