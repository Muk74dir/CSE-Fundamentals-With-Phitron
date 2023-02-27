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

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    node *CreateNode(int value)
    {
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
        }
        node *a = head;
        a->next = temp;
        temp->prev = a;
        head = a;
    }

    void insertTail(int value)
    {
        node *temp = CreateNode(value);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        node *a = tail;
        a->next = temp;
        temp->prev = a;
        tail = temp;
    }

    void insertMid(int value)
    {

    }

    void print()
    {
        node *a = head;
        while(tail.prev != NULL){
            a = a->next;
        }
    }
};



int main()
{


    return 0;
}
