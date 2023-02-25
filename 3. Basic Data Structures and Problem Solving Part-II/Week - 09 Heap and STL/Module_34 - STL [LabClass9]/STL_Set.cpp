#include<bits/stdc++.h>
using namespace std;


int main()
{
    set<int> st;
    //Insert : O(Log N)
    st.insert(5);
    st.insert(3);
    st.insert(4);
    st.insert(7);
    st.insert(3);
    st.insert(4);

    // int x = 4
    // auto y = x
    // auto will be int type;

    cout<<"Print Method : 1"<<endl; // O(n)
    for(auto i : st)
        cout<<i<<" ";
    cout<<endl;

    cout<<"Printing Method 2"<<endl; // O(n)
    for(auto it = st.begin(); it !=st.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"SET SIZE : "<<st.size()<<endl; // O(1)

    //Erase : O(log n)
    st.erase(5);

    cout<<"Printing set after erasing 5"<<endl; // O(n)
    for(auto i : st)
        cout<<i<<" ";
    cout<<endl;

    //Find : O(Log N) [Returns iterator's memory location, Not boolean]
    if(st.find(7) == st.end())cout<<"YES"; else cout<<"NO"; //[st.end() is not actually end]
    cout<<endl;

    if(st.find(100) != st.end())cout<<"YES"; else cout<<"NO"; //[For non existing value it returns end pointer]
    cout<<endl;


    return 0;
}
