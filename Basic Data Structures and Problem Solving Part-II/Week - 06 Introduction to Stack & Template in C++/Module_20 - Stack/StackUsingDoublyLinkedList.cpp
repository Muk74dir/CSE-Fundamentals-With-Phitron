#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;
};

class DoublyLL{
public:
    node *head;
    int sz;

    DoublyLL()
    {
        head = NULL;
        sz = 0;
    }

    int getSize(){
        return sz;
    }

    node *CreateNewNode(int data){
        sz++;
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }


    void InsertAtHead(int data){
        node *a = CreateNewNode(data);
        if(head == NULL){
            head = a;
        }
        else{
            head->prev = a;
            a->next = head;
            head = a;
        }
    }
    void DeleteAtHead(){
        if(head == NULL)return;

        node *x = head->next;
        delete head;

        if(x != NULL)
            x->prev = NULL;
        head = x;
        sz--;
    }

    void Traverse(){
        node *a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<endl;
    }

};

//Stack Using Linked List
class Stack{
public:
    DoublyLL dl;


    Stack()
    {

    }

    void Top(){
        if (dl.getSize()== 0){
            cout<<"Stack is Emty!"<<endl;
            return;
        }
        cout<<dl.head->data<<endl;
    }
    void Push(int value){
        dl.InsertAtHead(value);
    }
    void Pop(){
        if(dl.getSize()==0){
            cout<<"Stack is Already Emty!!!"<<endl;
            return;
        }
        dl.DeleteAtHead();
    }

};

int main()
{
    Stack st;
    st.Top();
    st.Push(10);
    st.Top();
    st.Push(20);
    st.Top();
    st.Push(30);
    st.Top();




    st.Pop();
    st.Top();

    st.Pop();
    st.Pop();
    st.Pop();
    st.Top();
    return 0;
}
