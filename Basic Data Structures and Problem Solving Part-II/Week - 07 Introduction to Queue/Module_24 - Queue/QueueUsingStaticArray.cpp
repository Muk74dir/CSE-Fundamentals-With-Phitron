 #include<bits/stdc++.h>
 using namespace std;
 const int MAX_SIZE = 5;

 class Queue{
 public:
     int a[MAX_SIZE];
     int l, r;

     Queue()
     {
         l=0;
         r=-1;
     }

     void Enqueue (int value)
     {
         if(r+1 >= MAX_SIZE){cout<<"NO SPACE"<<endl;return;}
         r++;
         a[r] = value;
     }

     void Dequeue ()
     {
         if(l > r){cout<<"ALREADY EMPTY!!"<<endl;return;}
         l++;
     }

     void front()
     {
         if(l > r){cout<<"EMPTY!!"<<endl;return;}
         cout<<a[l]<<endl;
     }

     int size(){return r-l +1;}

};

int main()
{
    Queue que;
    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    cout<<"SIZE : "<<que.size()<<endl;


    que.front();
    que.Dequeue();
    que.front();
    que.Dequeue();
    que.front();
    que.Dequeue();
    que.front();
    que.Dequeue();
    que.front();
    cout<<"SIZE : "<<que.size()<<endl;


    return 0;
}
