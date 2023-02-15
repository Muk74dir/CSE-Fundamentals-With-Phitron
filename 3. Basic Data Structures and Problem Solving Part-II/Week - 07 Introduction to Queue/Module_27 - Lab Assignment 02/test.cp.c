#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    int *a;
    int l, r;
    int cap;

    Queue()
    {
        l=0;
        r=-1;
        cap = 1;
        a = new int[cap];
    }

    void Resize()
    {
        cap = cap * 2;
        int *new_a = new int[cap];
        for(int i=l; i<=r; i++)
            new_a[i-l] = a[i];
        r = r-l;
        l = 0;
        delete[] a;
        a = new_a;
    }

    void Enqueue (int value)
    {
        if(r+1 >= cap) Resize();
        r++;
        a[r] = value;
    }

    void Dequeue()
    {
        if(l > r){
            cout<<"ALREADY EMPTY!!"<<endl;
            return;
        }
        l++;
    }

    void front()
    {
        if(l > r){
            cout<<"EMPTY!!"<<endl;
            return;
        }
        cout<<a[l]<<endl;
    }

    int size()
    {
        return r-l+1;
    }
};

int main()
{
    Queue que;
    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);
    que.Enqueue(60);
    que.Enqueue(70);
    que.Enqueue(80);
    que.Enqueue(90);
    for(int i=0; i<que.size(); i++){
        que.front();
        que.Dequeue();
    }

    cout<<que.size()<<endl;
}
