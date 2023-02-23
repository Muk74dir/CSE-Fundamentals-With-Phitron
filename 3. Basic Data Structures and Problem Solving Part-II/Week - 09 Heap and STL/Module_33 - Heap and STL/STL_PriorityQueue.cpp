#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>pq;
    pq.push(10); //O(Log N)
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(9);

    while(!pq.empty())
    {
        cout<<pq.top()<<" "; // O(1)
        pq.pop(); //O(Log N)
    }
    return 0;
}
