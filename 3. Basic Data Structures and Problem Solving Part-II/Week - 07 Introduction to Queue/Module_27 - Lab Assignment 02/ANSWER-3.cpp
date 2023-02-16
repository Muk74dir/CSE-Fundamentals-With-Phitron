#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
public:
    node<T>* prev;
    T data;
    node<T>* next;
};
template<class T>
class DLL{
public:
    node<T> *head;
    node<T> *tail;
    int sz;

    DLL()
    {
        head = NULL;
        tail = NULL;
        sz= 0;
    }

    node<T> *CreateNode(T value)
    {
        sz++;
        node<T> *newnode = new node<T>;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void InsertAtHead(T value)
    {
        node<T>* temp = CreateNode(value);
        if(head==NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void InsertAtTail(T value)
    {
        node<T> *temp = CreateNode(value);
        if(head==NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void DeleteAtHead()
    {
        node<T> *temp = head;
        if(head == NULL){return;}
        else
        {
            temp = head->next;
            swap(head, temp);
            delete temp;
            sz--;
        }
    }
    void DeleteAtTail()
    {
        if(tail == NULL){return;}
        else
        {
            node<T> *temp = tail;
            temp = tail->prev;
            tail = temp;
            sz--;
        }
    }
    T front()
    {
        if(sz==0){return 0;}
        return head->data;
    }
    T back()
    {
        if(sz==0){return 0;}
        return tail->data;
    }

};
template<class T>
class Deque{
public:
    DLL<T> dl;
    int sz;
    Deque()
    {
        sz = 0;
    }
    void Push_front(T value)
    {
        sz++;
        dl.InsertAtHead(value);
    }
    void Pop_front()
    {
        if(sz==0){cout<<"Already Empty"<<endl;return;}
        else
        {
            dl.DeleteAtHead();
            sz--;
        }
    }
    void Push_back(T value)
    {
        sz++;
        dl.InsertAtTail(value);
    }
    void Pop_back()
    {
        if(sz==0){cout<<"Already Empty"<<endl;return;}
        else
        {
            dl.DeleteAtTail();
            sz--;
        }
    }
    void Front()
    {
        if(sz==0){cout<<"Empty"<<endl;return;}
        cout<<dl.front()<<endl;
    }
    void Back()
    {
        if(sz==0){cout<<"Empty"<<endl;return;}
        cout<<dl.back()<<endl;
    }
    int Size()
    {
        return sz;
    }
};



int main()
{
    Deque<int> dq;
    dq.Push_back(30);
    dq.Push_back(10);
    dq.Push_front(20);
    dq.Push_back(40);
    dq.Push_front(80);
    cout<<dq.Size()<<endl;
    dq.Front();
    dq.Back();
    dq.Pop_front();
    dq.Pop_front();
    dq.Pop_front();
    dq.Pop_front();
    dq.Pop_back();
    dq.Front();
    dq.Back();
    cout<<dq.Size()<<endl;

    Deque<char> dq2;
    dq2.Push_back('A');
    dq2.Push_back('B');
    dq2.Push_front('C');
    dq2.Push_back('D');
    dq2.Push_front('E');
    cout<<dq2.Size()<<endl;
    dq2.Front();
    dq2.Back();
    dq2.Pop_front();
    dq2.Pop_front();
    dq2.Pop_front();
    dq2.Pop_front();
    dq2.Pop_back();
    dq2.Front();
    dq2.Back();
    cout<<dq.Size()<<endl;
}
