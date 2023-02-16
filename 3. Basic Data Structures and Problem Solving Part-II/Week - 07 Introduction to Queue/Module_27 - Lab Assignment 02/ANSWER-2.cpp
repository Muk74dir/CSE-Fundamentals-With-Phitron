#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
public:
    T data;
    node<T> *next;
};
template<class T>
class SLL{
public:
    node<T> *head;
    int sz;

    SLL()
    {
        head = NULL;
        sz = 0;
    }

    node<T> *CreateNode(T value)
    {
        sz++;
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
    void InsertAtHead(T value)
    {
        node<T> *temp = CreateNode(value);
        if(head == NULL){head = temp;}
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void DeleteAtHead()
    {
        node<T> *temp = head;
        temp = head->next;
        swap(head, temp);
        delete temp;
        sz--;
    }
    int Size()
    {
        return sz;
    }
};
template<class T>
class Stack{
public:
    SLL<T> sl;

    Stack()
    {

    }

    void Push(T value)
    {
        sl.InsertAtHead(value);
    }

    void Pop()
    {
        if(sl.Size()<=0){cout<<"Already Empty"<<endl;return;}
        else{sl.DeleteAtHead();}
    }
    void Top()
    {
        if(sl.Size()==0){cout<<"Stack is Empty"<<endl;return;}
        else{cout<<sl.head->data<<endl;}
    }
};

int main()
{
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

    Stack<char> st2;
    st2.Top();
    st2.Push('A');
    st2.Top();
    st2.Push('B');
    st2.Top();
    st2.Push('C');
    st2.Top();

    st2.Pop();
    st2.Top();

    st2.Pop();
    st2.Pop();
    st2.Pop();
    st2.Top();

    return 0;
}
