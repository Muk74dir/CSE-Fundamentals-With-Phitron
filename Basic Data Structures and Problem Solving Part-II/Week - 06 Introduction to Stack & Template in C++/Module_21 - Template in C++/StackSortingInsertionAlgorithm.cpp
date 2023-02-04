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

    T Top(){
        if (dl.getSize()== 0){
            cout<<"Stack is Emty!"<<endl;
            T a;
            return a;
        }
        return dl.head->data;
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

    int getSize(){

        return dl.getSize();
    }

};

int main()
{
    Stack<int> main;
    main.Push(5);
    main.Push(2);
    main.Push(7);
    main.Push(8);
    main.Push(3);                               // Time Complexity : O(n^2);

    Stack<int> temp;

    while(main.getSize()>0){
        int t = main.Top();
        main.Pop();
        while(temp.getSize()>0){

            if(temp.Top() <= t){
                break;
            }

            else{
                main.Push(temp.Top());
                temp.Pop();
            }
        }
        temp.Push(t);
    }
    swap(main, temp);

    while(main.getSize() > 0){
        cout<<main.Top()<<endl;
        main.Pop();
    }


    return 0;
}
