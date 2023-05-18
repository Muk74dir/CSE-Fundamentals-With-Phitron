#include<bits/stdc++.h>
using namespace std;

const int N = 101;
long long dp[N];

int main()
{
    int n;cin>>n;

    //1. Base Case :
    dp[1] =1;
    dp[2] = 1;

    //2. Loop through the states :
    for(int i=3; i<=n; i++){
        //3. Calclulate the answer from smaller sub-problem :
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<endl;


    return 0;
}
