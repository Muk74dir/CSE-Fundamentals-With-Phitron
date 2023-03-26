#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
int color[N];
vector<int>adj_list[N];

bool dfs(int src)
{
    visited[src] = 1;

    for(auto nxt : adj_list[src])
    {
        if(visited[nxt] == 0){
            if(color[src] == 1) color[nxt] = 2;
            else color[nxt] = 1;

            if(!dfs(nxt)){
                return false;
            }
        }
        else if(color[src] == color[nxt])return false;
    }

    return true;
}



int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
        adj_list[t].push_back(f);
    }

    for(int i=0; i<v; i++){
        if(visited[i] == 0){
            color[i] = 1;
            if(!dfs(i)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
