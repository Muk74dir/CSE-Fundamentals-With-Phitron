#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 5;

class Queue{
public:
    int a[MAX_SIZE];
    int sz;
    int l, r;

    Queue()
    {
        sz = 0;
        l = 0;
        r = -1;
    }

    void Enqueue (int value)
    {
        if(sz == MAX_SIZE)
        {
            cout<<"Queue is FULL!"<<endl;
            return;
        }
        a[l] = value;
        cout<<"OK"<<endl;
        r++;
        if(r == MAX_SIZE)
        {
            r=0;
            a[r] = value;
        }
        sz++;
    }

    void Dequeue ()
    {
        if(sz == 0)
        {
            cout<<"Queue is Already Empty!"<<endl;
            return;
        }
        cout<<"DELETED"<<endl;
        l++;
        if(l == MAX_SIZE){
            l = 0;
        }
        sz--;
    }

     void front ()
     {
         if(sz == 0)
            cout<<"EMPTY"<<endl;
         cout<<a[l]<<endl;
     }

     void size()
     {
         cout<<"SIZE : "<<sz<<endl;
     }


};

int main()
{
    Queue qu;
    qu.size();
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.Enqueue(40);
    qu.Enqueue(50);
    qu.Enqueue(60);
    qu.Enqueue(70);
    qu.size();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.size();


    return 0;
}
