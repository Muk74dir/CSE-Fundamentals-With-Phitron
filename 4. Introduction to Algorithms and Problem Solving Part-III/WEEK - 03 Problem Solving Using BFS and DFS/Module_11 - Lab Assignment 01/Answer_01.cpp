#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj_list[N];
int main()
{
    int n;cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;cin>>temp;
            if(temp == 1)
                adj_list[i].push_back(j);
        }
    }
    for(int i=0; i<n; i++){
        cout<<i<<": ";
        for(auto x : adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
