#include<bits/stdc++.h>
using namespace std;
const int N = 101;
long long dp[N];

long long fib(int n){ //1. State
    if(n<=2) return 1; //2. Base Case
    if(dp[n] == -1){
        dp[n] = fib(n-1) + fib(n-2); //3. Calculate from smaller sub-problems
    }
    return dp[n];

}

int main()
{
    int n;cin>>n;

    for(int i=1; i<=N; i++){
        dp[i] = -1; // mark all states unvisited
    }

    /* OR,
    memset(dp, -1, sizeof(dp));
    */

    cout<<fib(n)<<endl;
    return 0;
}
