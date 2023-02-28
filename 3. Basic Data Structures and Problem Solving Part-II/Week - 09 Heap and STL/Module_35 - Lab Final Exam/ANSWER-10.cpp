#include<bits/stdc++.h>
using namespace std;

int main()
{
    int temp;
    set<int>x;
    vector<int>v;

    int t;cin>>t;
    for(int i=0; i<t; i++){
        v.push_back(cin>>temp);
    }

    for(auto it = x.begin(); it != x.end(); it++){
        cout<<*it<<" ";
    }

    int t2;cin>>t2;
    for(auto it = x.begin(); it != x.end(); it++){
        cin>>temp;
        x.insert(temp);
    }

    return 0;
}
