#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];

bool dfs(int src)
{
    visited[src] = 1;

    for(auto nxt : adj_list[src]){
        if(visited[nxt] == 0){
            if(dfs(nxt)){
                return true;
            }
        }
        else if(visited[nxt] == 1){
            return true;
        }
    }

    return false;
}

int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
    }

    bool is_cyclic = false;

    for(int i=0; i<v; i++){
        if(visited[i] == 0){
            if(dfs(i)){
                is_cyclic = true;
                break;
            }
        }
    }

    if(is_cyclic){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
