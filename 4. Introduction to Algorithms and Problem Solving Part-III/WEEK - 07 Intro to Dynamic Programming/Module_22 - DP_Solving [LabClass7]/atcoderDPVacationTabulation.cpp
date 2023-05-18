/* TASK C: Vacation - https://atcoder.jp/contests/dp/tasks/dp_c
===========================================================

- state: fun(n, x) -> maximum happiness till day-n
                      if we pick task-x on day-n

- recurrance: fun(n, x) = max {
                            fun(n - 1, y) where x != y
                            + happiness[n][x]
                         }
- base case: fun(1, x) = ha ppiness[1][x]
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int happiness[N][4], dp[N][4];

int main(){
    int n;cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin>>happiness[i][j];
        }
    }

    //1. Base Case :
    for(int task=1; task<=3; task++){
        dp[1][task] = happiness[1][task];
    }

    //2. Loop Over the states :
    for(int day=1; day<=n; day++){
        for(int curr_task=1; curr_task<=3; curr_task++){
            //3. Calculate Smaller sub-problems
            int max_hap = -1;
            for(int last_task=1; last_task<=3; last_task++){
                if(last_task == curr_task) continue;
                int candidate_hap = dp[day-1][last_task] + happiness[day][curr_task];
                max_hap = max(max_hap, candidate_hap);
            }
            dp[day][curr_task] = max_hap;
        }
    }
    int ans = max({dp[n][1], dp[n][2], dp[n][3]});
    cout<<ans<<endl;

}
