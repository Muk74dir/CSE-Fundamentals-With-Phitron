#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> qu;
    //enqueue O(1)
    qu.push(10);        //enqueue
    qu.push(20);
    qu.push(30);        //10, 20, 30]
    cout<<qu.size()<<endl;
    cout<<qu.front()<<endl;
    //dequeue o(1)
    qu.pop();          //dequeue [20, 30]
    cout<<qu.front()<<endl;
    qu.pop();
    qu.pop();
    cout<<qu.size()<<endl;

    //empty O(1)
    if(qu.empty())
        cout<<"True"<<endl;
    cout<<qu.empty()<<endl;     //if True it returns 1



    queue<char>qu2;
    qu2.push('A');
    qu2.push('B');
    qu2.push('C');
    qu2.pop();
    cout<<qu2.front()<<endl;    //B

    return 0;
}
