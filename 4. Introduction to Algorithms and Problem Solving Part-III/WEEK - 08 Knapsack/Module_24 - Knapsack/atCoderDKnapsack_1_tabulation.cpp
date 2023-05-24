/* atcoder Task-D : Knapsack-1 : https://atcoder.jp/contests/dp/tasks/dp_d
==========================================================================
    - state: knapsack(n, cap) -> maximum profit considering objects 1 to n and capacity=cap
    - recurrance:
        knapsack(n, cap) -> max {
                                val[n] + knapsack(n - 1, cap - wt[n]),
                                knapsack(n - 1, cap)
                            }
    - base_case: knapsack(0, x) = 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 102;
const int M = 1e5+5;
long long dp[N][M];
int wt[N], val[N];

int main()
{
    int n, w;cin>>n>>w;
    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++){
        cin>>wt[i]>>val[i];
    }

    //1.Handle Base Case :
    for(int i=0; i<=w; i++){
        dp[0][i] = 0;
    }

    //2. Loop over the states :
    for(int i=1; i<=n; i++){
        for(int cap=0; cap<=w; cap++){
            //3. Calculate the result from smaller sub-problems.
            if(cap<wt[i]){
                dp[i][cap] = dp[i-1][cap];
            }
            else{
                dp[i][cap] = max( val[i]+dp[i-1][cap-wt[i]], dp[i-1][cap] );
            }
        }
    }

    cout<<dp[n][w]<<endl;
    return 0;
}
