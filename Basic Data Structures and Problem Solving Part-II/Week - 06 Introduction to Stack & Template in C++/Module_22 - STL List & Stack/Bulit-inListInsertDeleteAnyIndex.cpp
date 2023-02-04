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
void Insert(list<int>&l, int index, int value)
{
    auto it = l.begin();
    advance(it, index);
    l.insert(it, value);

}
void Delete(list<int>&l, int index)
{
    auto it = l.begin();
    advance(it, index);
    l.erase(it);
}

int main()
{
    list<int> l;//O(1)
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    print(l);


    //insert at any position
    Insert(l, 2, 500);
    print(l);


    Delete(l, 2);
    print(l);

    cout<<l.size()<<endl;

    return 0;
}
