/*

Problem atcoder Link : https://atcoder.jp/contests/dp/tasks/dp_b
================================================================

- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = for i = 1 to  k:
                            min(
                                stone(n-i) + abs( h[n] - h[n-i])
                            )
- base case: stone(1) = 0



i   <====(i-1), (i-2) ... (i-k)

k = 4

i = 2
2  <=====(2-1), (2-2) ... (2-4)
          1,   0 , -1,  -2

*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int N = 1e5+5;
int h[N], dp[N];
int n, k;

int stone_2(int n){
    if(n==1) return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = INF;
    for(int i=1; i<=k; i++){
        //Handle Corner Case :
        if(n-i<=0) break;

        int candidate_ans = stone_2(n-i) + abs( h[n] - h[n-i] );
        ans = min(ans, candidate_ans);
    }
    dp[n] = ans;
    return dp[n];

}


int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    memset(dp, -1, sizeof(dp));

    cout<<stone_2(n)<<endl;

    return 0;
}
