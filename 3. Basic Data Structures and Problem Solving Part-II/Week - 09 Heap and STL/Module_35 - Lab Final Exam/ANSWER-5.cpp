#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class Queue{
public:
    int arr[MAX_SIZE];
    int l, r, sz;

    Queue()
    {
        sz = 0;
        l = 0;
        r = -1;
    }

    void enqueue(int value)
    {
        if(r+1 >= MAX_SIZE)
        {
            cout<<"NO SPACE !!"<<endl;
            return;
        }
        else
        {
            r++;
            arr[r] = value;
            sz++;
        }
    }

    void dequeue()
    {
        if(r<l){
            cout<<"Already Empty !!"<<endl;
            return;
        }
        else
        {
            arr[l] = 0;
            l++;
            sz--;
        }
    }

    void Front()
    {
        if(r<l){
            cout<<"EMPTY!!"<<endl;
            return;
        }
        cout<<"FRONT : "<<arr[l]<<endl;
    }

    void print()
    {
        if(sz==0){
            cout<<"Nothing in Queue"<<endl;
            return;
        }
        for(int i=l; i<=r; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void Size(){
        cout<<"SIZE : "<<sz<<endl;
    }

};




int main()
{
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.enqueue(50);
    qu.Front();
    qu.print();
    qu.Size();

    qu.dequeue();
    qu.Front();
    qu.print();
    qu.Size();

    qu.dequeue();
    qu.Front();
    qu.print();
    qu.Size();

    qu.enqueue(1000);
    qu.Front();
    qu.print();
    qu.Size();

    return 0;
}
