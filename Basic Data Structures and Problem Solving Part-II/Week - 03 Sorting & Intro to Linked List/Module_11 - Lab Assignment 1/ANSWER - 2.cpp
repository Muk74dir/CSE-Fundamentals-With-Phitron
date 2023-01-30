#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin>>n;
    vector<int> x(n+1);
    for(int i=1; i<n; i++){
        cin>>p;
        x[p] = 1;
    }
    for(int i=1; i<=n; i++){
        if(x[i]!=1)
            cout<<i;
    }
    return 0;
}
