#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};

class QueuePlusSLL{
public:
    node *head;
    node *tail;
    int sz;

    QueuePlusSLL()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNode(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void Enqueue(int value)
    {
        sz++;
        node* newnode = CreateNode(value);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            cout<<"OK"<<endl;
            return;
        }
        else
        {
            cout<<"OK"<<endl;
            tail->next = newnode;
            tail = newnode;
        }
    }

    void Dequeue()
    {
        if(sz==0)
            cout<<"Already Empty\n";
        else if(sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            cout<<"OK"<<endl;
            sz--;
        }
        else
        {
            node *a= head;
            head = head->next;
            sz--;
            cout<<"OK"<<endl;
            delete a;
        }
    }

    void front()
    {
        if(sz <= 0)
            cout<<"Empty\n";
        else if(sz>0)
        {
            cout<<head->data<<endl;
        }

    }

    void size()
    {
        cout<<"SIZE : "<<sz<<endl;
    }

};


int main()
{
    QueuePlusSLL qu;
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.front();
    qu.size();

    qu.Dequeue();
    qu.front();

    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.front();
    qu.size();
    return 0;
}
