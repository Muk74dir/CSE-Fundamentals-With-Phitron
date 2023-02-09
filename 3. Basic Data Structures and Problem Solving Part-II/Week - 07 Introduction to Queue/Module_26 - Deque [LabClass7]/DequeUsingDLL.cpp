#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node* prev;
    int data;
    node* next;
};

class Deque{
public:
    node *head;
    node *tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNode(int value)
    {
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void push_back(int value)
    {
        node *a = CreateNode(value);
        if(sz == 0)
        {
            head = a;
            tail = a;
        }
        else
        {
            tail->next = a;
            a->prev = tail;
            tail = a;
            delete a;
        }
        sz++;
    }

    void push_front(int value)
    {
        node *a = CreateNode(value);
        if(sz == 0)
        {
            head = a;
            tail = a;
        }
        else
        {
            head->prev =a;
            a->next = head;
            head = a;
            delete a;
        }
        sz++;
    }


};

int main()
{


    return 0;
}
