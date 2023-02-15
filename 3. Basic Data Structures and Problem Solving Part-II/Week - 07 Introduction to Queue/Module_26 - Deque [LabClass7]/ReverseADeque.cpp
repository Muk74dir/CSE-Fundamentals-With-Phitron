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
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node *CreateNode(int value)
    {
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
    void InsertAtTail(int value)
    {

    }
    void InsertAtHead(int value)
    {
        node *a = CreateNode(value);
        if(sz == 0)
        {
            cout<<"OK"<<endl;
            head = a;
            tail = a;
        }
        else
        {
            cout<<"OK"<<endl;
            head->prev = a;
            a->next = head;
            head = a;
        }
        sz++;
    }

    void push_back(int value)
    {
        if(rev==0)
        {
            InsertAtTail(value);
        }
        else
        {
            InsertAtHead(value);
        }
    }

    void push_front(int value)
    {
        if(rev==0)InsertAtHead(value);
        else InsertAtTail(value);
    }
    void DeleteFirst()
    {
        if(sz == 0)
        {
            cout<<"Already Empty\n";
            return;
        }
        else if(sz == 1)
        {
            cout<<"OK"<<endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            cout<<"OK"<<endl;
            node *a = head;
            delete head;
            a = a->next;
            a->prev = NULL;
            head = a;
        }
        sz--;
    }

    void DeleteLast()
    {
        if(sz == 1)
        {
            cout<<"OK"<<endl;
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else if(sz == 0)
        {
            cout<<"Already Empty\n";
            return;
        }
        else
        {
            cout<<"OK"<<endl;
            node *a = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete a;

        }
        sz--;
    }

    void pop_back()
    {
        if(rev==0)DeleteLast();
        else DeleteFirst();
    }

    void pop_front()
    {
        if(rev==0)DeleteFirst();
        else DeleteLast();
    }

    void front()
    {
        if(sz==0){cout<<"Deque is Empty"<<endl;return;}
        if(rev == 0){cout<<head->data<<endl;}
        else{cout<<tail->data<<endl;}
    }

    void back(){
        if(sz==0){cout<<"Deque is Empty"<<endl;return;}
        if(rev == 0){cout<<tail->data<<endl;}
        else{cout<<head->data<<endl;}
    }

    void Traverse()
    {
        node *a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<endl;
    }

    void size()
    {
        cout<<sz<<endl;
    }

    //Reverse a Deque in O(1)
    void Reverse()
    {
        if(rev == 0){rev = 1;}
        else {rev = 0;}
    }

};

int main()
{
    Deque d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.Reverse();

    cout<<"Deque : ";d.Traverse();



    return 0;
}
