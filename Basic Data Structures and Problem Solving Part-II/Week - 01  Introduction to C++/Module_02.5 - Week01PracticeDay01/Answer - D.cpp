#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin>>n;
    vector<int> x(n);
    for(int i=1; i<n; i++){
        cin>>p;
        x[p] = 1;
    }
    for(int i=1; i<=n; i++){
        if(x[i]==0)
            cout<<i;
    }
    return 0;
}
