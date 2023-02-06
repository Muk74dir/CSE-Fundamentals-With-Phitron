#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList
{
public:
    node *head;
    node *tail;
    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }



    void Traverse()
    {
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    int getSize()
    {
        return sz;
    }
    void printReverse(){
        node* a = head;
        reverse(a);
        cout<<"\n";
    }

    void reverse(node* a){
        if (a == NULL) return;
        reverse(a->nxt);

        cout<<a->data<<" ";
    }


    void deleteZero()
    {
        node *a = head;
        while (a != NULL)
        {
            if (a->data == 0)
            {
                if (a == head)
                {
                    head = a->nxt;
                    head->prv = NULL;
                }
                else if (a->nxt == NULL)
                {
                    tail = a->prv;
                    tail->nxt = NULL;
                }
                else
                {
                    a->prv->nxt = a->nxt;
                    a->nxt->prv = a->prv;
                }
                node *temp = a;
                a = a->nxt;
                delete temp;
            }
            else
            {
                a = a->nxt;
            }
        }
        Traverse();
    }


    void swap(int i, int j){
        i--, j--;
        node *current_i = head;
        node *current_j = head;
        node *prev_i = NULL;
        node *prev_j = NULL;

        int count = 0;
        while (count < i){
            prev_i = current_i;
            current_i = current_i->nxt;
            count++;
        }

        count = 0;
        while (count < j){
            prev_j = current_j;
            current_j = current_j->nxt;
            count++;
        }

        if (prev_i != NULL){
            prev_i->nxt = current_j;
        }
        else{
            head = current_j;
        }

        if (prev_j != NULL){
            prev_j->nxt = current_i;
        }
        else{
            head = current_i;
        }

        node *temp = current_i->nxt;
        current_i->nxt = current_j->nxt;
        current_j->nxt = temp;

        printReverse();

        }




};

int main()
{
    DoublyLinkedList dl;
    DoublyLinkedList dl2;
    vector<int>x = {0, 2, 0, 0, 5};
    for(int i : x)
        dl.InsertAtHead(i);

    dl.deleteZero();

    vector<int>y = {3, 2, 6, 4, 7};
    for(int j : y)
        dl2.InsertAtHead(j);

    dl2.swap(1, 4);


    return 0;
}
