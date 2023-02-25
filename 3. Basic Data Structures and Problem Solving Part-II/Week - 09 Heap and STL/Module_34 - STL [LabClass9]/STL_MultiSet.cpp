#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int>a;
    //Insert : O(Log N)
    a.insert(5);
    a.insert(7);
    a.insert(4);
    a.insert(3);
    a.insert(4);
    a.insert(7);

    //print : O(n)
    cout<<"Printing The Multiset : "<<endl;
    for(auto it : a)
        cout<<it<<" ";
    cout<<endl;

    cout<<"SIZE : "<<a.size()<<endl;

    //Erase : O(Log N)
    a.erase(4);//erase all occurrence of that value;
    cout<<"Printing The Multiset : After erasing 4 "<<endl;
    for(auto it : a)
        cout<<it<<" ";
    cout<<endl;


    //Erase a single occurrence
    a.erase(4);
    cout<<"Printing The Multiset : After erasing a single occurrence"<<endl;
    for(auto it : a)
        cout<<it<<" ";
    cout<<endl;

    //Find : O(Log N)
    if(a.find(4) != a.end())cout<<"YES";else cout<<"NO";
    cout<<endl;
    if(a.find(5) != a.end())cout<<"YES";else cout<<"NO";
    cout<<endl;

    return 0;
}
