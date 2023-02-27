#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;
};

class LinkedList{
public:
    node *head;
    node *tail;
    int sz;

    LinkedList()
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

    void Merge(LinkedList temp)
    {
        tail->next = temp.head;
        temp.head->prev = tail;
    }
};

int main()
{
    LinkedList a;
    LinkedList b;
    a.insertHead(1);
    a.insertTail(5);
    a.insertMid(3);
    a.insertHead(0);
    a.insertTail(10);

    a.print(); // prints 0 1 3 5 10

    b.insertHead(10);
    b.insertTail(50);
    b.insertMid(30);
    b.insertHead(9);
    b.insertTail(100);

    b.print(); // prints 9 10 30 50 100

    a.Merge(b);

    a.print(); // prints 0 1 3 5 10 9 10 30 50 100
    b.print(); // prints 9 10 30 50 100

    return 0;
}
