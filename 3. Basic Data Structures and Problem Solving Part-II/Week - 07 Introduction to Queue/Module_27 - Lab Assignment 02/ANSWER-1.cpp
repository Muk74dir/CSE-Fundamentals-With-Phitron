#include<bits/stdc++.h>
 using namespace std;

 template<class T>
 class Queue{
 public:
     T *a;
     int l, r;
     int cap;
     int sz;

     Queue()
     {
         l=0;
         r=-1;
         cap = 1;
         a = new T[cap];
         sz = 0;
     }

     void Resize()
     {
        cap = cap * 2;
        T *new_a = new T[cap];
        for(int i=l; i<=r; i++)
            new_a[i] = a[i];
        swap(a, new_a);
        delete [] new_a;
     }

    void Enqueue (T value)
    {
        if(r+1 >= cap){Resize();}
        r++;
        a[r] = value;
        sz++;
    }

    void Dequeue()
    {
        if(l > r){cout<<"ALREADY EMPTY!!"<<endl;return;}
        else {l++; sz--;}
    }

    void front()
    {
        if(l > r){cout<<"EMPTY!!"<<endl;return;}
        cout<<a[l]<<endl;
    }

    int size(){return sz;}

};

int main()
{
    Queue<int> que;
    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);
    que.Enqueue(60);
    que.Enqueue(70);
    que.Enqueue(80);
    que.Enqueue(90);

    cout<<"SIZE AFTER ENQUEUE : "<<que.size()<<endl;
    int sz = que.size();
    for(int i=0; i<sz; i++){
        que.front();
        que.Dequeue();
    }
    cout<<"SIZE AFTER DEQUEUE : "<<que.size()<<endl;

    Queue<char> que2;
    que2.Enqueue('A');
    que2.Enqueue('B');
    que2.Enqueue('C');
    que2.Enqueue('D');
    que2.Enqueue('E');
    que2.Enqueue('F');

    cout<<endl;
    cout<<endl;

    cout<<"SIZE AFTER ENQUEUE : "<<que2.size()<<endl;
    int sz2 = que2.size();
    for(int i=0; i<sz2; i++){
        que2.front();
        que2.Dequeue();
    }
    cout<<"SIZE AFTER DEQUEUE : "<<que2.size()<<endl;

    return 0;
}
