#include<bits/stdc++.h>
using namespace std;

int max_ele(vector<int> x, int t, int maxi){
    if(t<0)return maxi;
    if(maxi < x[t]) maxi = x[t];
    maxi = max_ele(x, t-1, maxi);
    return maxi;
}

int main(){
    int t;cin>>t;
    int maxi = -99999999;
    vector<int>x(t);
    for(int i=0; i<t; i++)
        cin>>x[i];

    cout<<max_ele(x, t-1, maxi)<<endl;

    return 0;
}
