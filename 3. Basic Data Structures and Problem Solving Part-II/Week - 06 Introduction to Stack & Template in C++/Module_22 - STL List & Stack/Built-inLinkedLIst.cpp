#include<bits/stdc++.h>
using namespace std;

//O(n)
void print(list<int>l)
{
    list<int>::iterator a = l.begin();      // auto a = l.begin()
    while(a != l.end())
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<endl;
}

int main()
{
    list<int> l;//O(1)
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);   // 30 20 10
    print(l);

    l.push_back(40);
    l.push_back(50);    // 30 20 10 40 50
    print(l);

    l.pop_back();       // 30 20 10 40
    print(l);

    l.pop_front();      // 20 10 40
    print(l);

    return 0;
}
