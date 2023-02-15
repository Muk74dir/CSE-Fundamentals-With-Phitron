#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int>dq;
    dq.push_back(20);
    dq.push_front(30);
    dq.push_back(40);
    dq.push_front(50);
    // [50, 30, 20, 40]
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}
