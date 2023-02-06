#include<bits/stdc++.h>
using namespace std;

//Queue Using Dynamic Circular Array.

class Queue{
public:
    int *a;
    int sz;
    int l, r;
    int cap;

    Queue()
    {
        sz = 0;
        l = 0;
        r = -1;
        cap = 1;
        a = new int[cap];
    }

    void Break_Circular()
    {
        if(l>r)
        {
            int *temp = new int[cap];
            int idx = 0;
            for(int i=l; i<cap; i++){
            temp[idx] = a[i];
            idx++;
            }
            for(int j=0; j<=r; j++){
                temp[idx] = a[j];
                idx++;
            }
            l = 0;
            r = cap-1;
            swap(a, temp);
            delete [] temp;
        }
    }
    //size increase;
    void Increase_Size()
    {
        Break_Circular();
        int *temp = new int[cap*2];
        for(int i=0; i<cap; i++)
            temp[i] = a[i];
        swap(a, temp);
        cap = cap*2;
        delete []temp;

    }

    void Enqueue (int value)
    {
        if(sz == cap)
        {
            Increase_Size();
        }
        a[l] = value;
        cout<<"OK"<<endl;
        r++;
        if(r == cap)
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
        if(l == cap){
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
