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

long long knapsack(int n, int cap){
    //1. Base Case :
    if(n == 0)return 0;

    //2. If result is already calculated for this case :
    if(dp[n][cap] != -1 ) return dp[n][cap];

    //3. Calculate result from smaller subproblems.
    if(cap < wt[n]){
        long long ans =  knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    long long ans1 = val[n] + knapsack(n-1, cap-wt[n]);
    long long ans2 = knapsack(n-1, cap);


    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;
    return ans;

}


int main()
{

    int n, cap;cin>>n>>cap;
    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++){
        cin>>wt[i]>>val[i];
    }

    cout<<knapsack(n, cap)<<endl;


    return 0;
}
