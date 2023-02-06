#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    if(n>3){
    for(int j=2; j<=n; j+=2)
        cout<<j<<" ";
    for(int i=1; i<=n; i+=2)
        cout<<i<<" ";
    }
    else if(n==1)cout<<1;
    else
        cout<<"NO SOLUTION";
    return 0;
}
