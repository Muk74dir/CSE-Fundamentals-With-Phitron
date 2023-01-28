#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};

class LinkedList{
public:
    node *head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz = 0;
    }
    node* CreateNewNode(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void InsertAtHead(int value){
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL){
            head = a;
        }
        else{
            a->next = head;
            head = a;
        }
    }

    void Traverse(){
        node *a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<"\n";
    }

    int SearchValueIndex(int value){
        node *a = head;
        int ind = 0;
        while(a != NULL){
            if(a->data == value){
                return ind;
            }
            else{
                a = a->next;
                ind++;
            }
        }
        return -1;
    }

//    int getSize(){
//        node *a = head;
//        int cnt = 0;
//        while(a!=NULL){           // O(n)  : not good  XX
//            cnt++;
//            a = a->next;
//        }
//        return cnt;
//    }
    int getSize(){
        return sz;      //O(1)
    }


    void InsertAtAnyIndex(int index, int value){

        if(index<0 || index>sz)
        {
            return;
        }

        if(index == 0){
            InsertAtHead(value);
            return;
        }
        sz++;
        node *a = head;
        int crntind = 0;
        while(crntind != index-1){
            a = a->next;
            crntind++;
        }
        node *tempnode = CreateNewNode(value);
        tempnode->next = a->next;
        a->next = tempnode;
    }



};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.Traverse();
    cout<<l.SearchValueIndex(10)<<endl;
    cout<<"Size : "<<l.getSize()<<endl;
    l.InsertAtHead(10);
    l.Traverse();
    l.InsertAtHead(20);
    l.Traverse();
    l.InsertAtHead(30);
    l.Traverse();
    cout<<"Size : "<<l.getSize()<<endl;


    l.InsertAtAnyIndex(5, 500);
    l.Traverse();
    cout<<"Size : "<<l.getSize()<<endl;
    return 0;
}
