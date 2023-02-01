#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node * nxt;
};

class LinkedList{
public:
    node * head;
    int sz;
    LinkedList(){
        head = NULL;
        sz=0;
    }

    node* CreateNewNode(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(int value){
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL){
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }

    void Traverse(){
        node* a = head;
        while(a!= NULL){
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    int getSize(){
        return sz;
    }

    int getLast(){
        if(head == NULL)return -1;
        return head->data;
    }

    double getAverage(){
        double avg;
        node* a = head;
        while(a!= NULL){
            avg += a->data;
            a = a->nxt;
        }
        return avg/getSize();
    }


};

int main()
{
    LinkedList l;
    LinkedList l2;
    vector<int>input = {3, 2, 6, 4, 5};
    vector<int>input2 = {3, 2, 6, 4, 7};
    for(int i : input)
        l.InsertAtHead(i);
    for(int j : input2)
        l2.InsertAtHead(j);
    cout<<l.getLast()<<endl;
    cout<<l2.getAverage();
    return 0;
}
