#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:
    node *prev;
    T data;
    node *next;
};
template<class T>
class DoublyLL{
public:
    node<T> *head;
    int sz;

    DoublyLL()
    {
        head = NULL;
        sz = 0;
    }

    int getSize(){
        return sz;
    }

    node<T> *CreateNewNode(T data){
        sz++;
        node<T> *newnode = new node<T>;
        newnode->prev = NULL;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }


    void InsertAtHead(T data){
        node<T> *a = CreateNewNode(data);
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

        node<T> *x = head->next;
        delete head;

        if(x != NULL)
            x->prev = NULL;
        head = x;
        sz--;
    }

};

//Template Based Stack Using Linked List
template<class T>
class Stack{
public:
    DoublyLL<T> dl;


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
    void Push(T value){
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
    cout<<"FOR INT"<<endl;
    Stack<int> st;
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
    cout<<endl;


    cout<<"FOR CHAR"<<endl;
    Stack<char> st2;
    st2.Top();
    st2.Push('f');
    st2.Top();
    st2.Push('r');
    st2.Top();
    st2.Push('u');
    st2.Top();

    st2.Pop();
    st2.Top();

    st2.Pop();
    st2.Pop();
    st2.Pop();
    st2.Top();
    cout<<endl;

    cout<<"FOR STRING"<<endl;
    Stack<string> st3;
    st3.Top();
    st3.Push("AMI");
    st3.Top();
    st3.Push("MUKTADIR");
    st3.Top();
    st3.Push("BOLCHI");
    st3.Top();


    st3.Pop();
    st3.Top();

    st3.Pop();
    st3.Pop();
    st3.Pop();
    st3.Top();

    return 0;
}
