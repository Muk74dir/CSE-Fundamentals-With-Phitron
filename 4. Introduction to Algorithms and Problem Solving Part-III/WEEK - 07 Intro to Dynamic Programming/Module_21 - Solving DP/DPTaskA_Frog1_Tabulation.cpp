/* Frog 1 : https://atcoder.jp/contests/dp/tasks/dp_a
===================================================== */

// METHOD : TABULATION

/*
- State : Stone(n) --> cost of reaching n-th  stone from 1st stone.
- Recurrance State(n) = min { (stone(n-1) + abs( h[n] - h[n-1] )
                              (stone(n-2) + abs( h[n] - h[n-2] )
                            }

- Base Case : Stone(1) = 0

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int h[N], dp[N];

int main()
{
    int n;cin>>n;

    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    memset(dp, -1, sizeof(dp));

    //1. Handle Base Case :
    dp[1] = 0;
    //2. Loop through the states :
    for(int i=2; i<=n; i++){
        //3. Solve from smaller sub-problems
        int ans1 = dp[i-1]+abs(h[i] - h[i-1]);
        if(i == 2){
            dp[i] = ans1; // Corner Case.
            continue;
        }
        int ans2 = dp[i-2]+abs(h[i] - h[i-2]);
        dp[i] = min(ans1, ans2);
    }

    cout<<dp[n]<<endl;

    return 0;
}

