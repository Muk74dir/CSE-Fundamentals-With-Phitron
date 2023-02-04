#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.top()<<endl;
    cout<<"Stack Size : "<<st.size()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<"Stack Size : "<<st.size()<<endl;

    return 0;
}
