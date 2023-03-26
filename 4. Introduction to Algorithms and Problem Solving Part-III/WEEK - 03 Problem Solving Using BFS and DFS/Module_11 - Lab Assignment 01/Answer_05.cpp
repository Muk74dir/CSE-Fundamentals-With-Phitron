#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int>adj_list[N];

void dfs(int src)
{
    visited[src] = 1;

    for(auto nxt : adj_list[src])
    {
        if(visited[nxt] == 0){
            visited[nxt] = 1;
            dfs(nxt);
        }
    }

}


int main()
{
    int v, e;cin>>v>>e;
    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
        adj_list[t].push_back(f);
    }
    int cnt = 0;
    for(int i=0; i<v; i++)
    {
        if(visited[i] == 0){
            cnt ++;
            dfs(i);
        }
    }

    cout<<cnt<<endl;

    return 0;
}
