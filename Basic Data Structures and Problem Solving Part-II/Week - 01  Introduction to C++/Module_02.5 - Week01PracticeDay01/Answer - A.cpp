#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, cnt=0;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n; i++)
        cin>>x[i];
    sort(x.begin(), x.end());
    for(int j=0; j<n; j++){
        if(j==0){
            cnt++;
            continue;
        }
        if(x[j] != x[j-1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
