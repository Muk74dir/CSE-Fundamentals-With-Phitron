/* Frog 1 : https://atcoder.jp/contests/dp/tasks/dp_a
===================================================== */

// METHOD : MEMOIZATION

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
int h[N];
int dp[N];

int stone(int n){
    //1.Base Case :
    if(n == 1) return 0;

    //2. Check if answer already exist.
    if(dp[n] == -1 && n!=2){
        dp[n] = min( (stone(n-1)+abs(h[n]-h[n-1]) ), (stone(n-2)+abs(h[n] - h[n-2])) );
    }
    else if(dp[n] == -1 && n == 2){
        dp[n] = stone(n-1)+abs(h[n]-h[n-1]); // for n = 2 is a Corner Case.
    }

    return dp[n];
}

int main()
{
    int n;cin>>n;

    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<stone(n)<<endl;

    return 0;
}
