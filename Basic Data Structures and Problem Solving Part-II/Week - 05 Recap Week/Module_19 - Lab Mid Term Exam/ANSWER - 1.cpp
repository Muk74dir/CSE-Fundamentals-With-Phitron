#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    vector<int>a(t);
    for(int i=0; i<a.size(); i++)
        cin>>a[i];
    for(int j=a.size()-1; j>=0; j--)
        cout<<a[j]<<" ";

    return 0;
}
