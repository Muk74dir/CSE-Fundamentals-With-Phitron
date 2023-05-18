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

int fun(int day, int task){
    //1. Handle Base Case :
    if(day == 1) return happiness[day][task];

    //2. If answer is already calculte :
    if(dp[day][task] != -1){
        return dp[day][task];
    }

    int max_hap = -1;

    //3. calculate the smaller sub-problem :
    for(int last_task =1; last_task<=3; last_task++){
        if(last_task == task)continue;
        int candidate_hap = fun(day-1, last_task) + happiness[day][task];
        max_hap = max(max_hap, candidate_hap);
    }
    dp[day][task] = max_hap;
    return max_hap;
}



int main()
{
    int n;cin>>n;
    for(int i=1; i<=n; i++){
//        int a, b, c;
//        cin>>a>>b>>c;
//        happiness[i][1] = a;
//        happiness[i][2] = b;
//        happiness[i][3] = c;
        for(int j=1; j<=3; j++){
            cin>>happiness[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            dp[i][j] = -1;
        }
    }

    int ans_1 = fun(n, 1);
    int ans_2 = fun(n, 2);
    int ans_3 = fun(n, 3);

    cout<< max({ans_1, ans_2, ans_3}) <<endl;

    return 0;
}
