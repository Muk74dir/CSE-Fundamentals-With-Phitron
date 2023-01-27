#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];
    int a;cin>>a;
    int b;cin>>b;
    x.erase(x.begin()+a-1, x.begin()+b);
    for(int j=0; j<x.size(); j++)
        cout<<x[j]<<" ";
    return 0;
}
