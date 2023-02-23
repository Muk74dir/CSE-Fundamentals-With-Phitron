// n, 2 array 2 & b. how many operation we need to make the array same. [a == b](including reverse), replaced by digit.

#include<bits/stdc++.h>
using namespace std;

int digit(int x)
{
    int cnt = 0;
    while (x != 0){
        x = x / 10;
        cnt++;
    }
    return cnt;
}


int main()
{
    int n;cin>>n;                                   // INPUT : 2
    vector<int>a(n);                                //         2 10
    vector<int>b(n);                                //         10 20
    for(int i=0; i<n; i++)
        cin>>a[i];                                  // OUTPUT : 1
    for(int j=0; j<n; j++)
        cin>>b[j];

    priority_queue<int>p1;
    priority_queue<int>p2;
    for(int i=0; i<n; i++){
        p1.push(a[i]);
        p2 .push(b[i]);
    }
    int ans = 0;
    while(p1.size())
    {
        int x = p1.top();
        int y = p2.top();
        if(x==y){
            p1.pop();
            p2.pop();
            continue;
        }
        ans++;
        if(x > y){
            p1.pop();
            p1.push(digit(x));
        }
        else{
            p2.pop();
            p2.push(digit(y));
        }
    }

    cout<<ans<<endl;

    return 0;
}
