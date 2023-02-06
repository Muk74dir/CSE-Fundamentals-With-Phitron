#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;cin>>t;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];

    sort(x.begin(), x.end());

    for(int i=1; i<x.size(); i++){
        if(i == 1) cout<<x[0]<<" ";
        if(x[i-1] != x[i])
            cout<<x[i]<<" ";
    }
    return 0;
}
