#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    map<string, int>mp;
    for(int i=0; i<t; i++)
    {
        string temp;
        cin>>temp;
        if(mp.count(temp))
        {
            cout<<mp[temp]<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        mp[temp] = i;
    }

    return 0;
}
