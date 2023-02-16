#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;cin>>st;
    deque<char> dq;

    for(int i=0; i<st.size(); i++){
        dq.push_back(st[i]);
    }
    for(int j=0; j<st.size()/2; j++)
    {
        if(dq.front() == dq.back())
        {
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
