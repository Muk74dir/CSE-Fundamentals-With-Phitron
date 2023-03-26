/*

Topological Sort
===============

Problem : Course Schedule : https://cses.fi/problemset/task/1679
=================================================================

Input:
5 3
1 2
3 1
4 5

Output:
3 4 1 5 2

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];
stack<int>ans;

void dfs(int src)
{
    visited[src] = 1;

    for(auto adj_node : adj_list[src]){
        if(visited[adj_node] == 0){
            dfs(adj_node);
        }
    }
    ans.push(src);
}

int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
    }

    for(int i=1; i<=v; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

    return 0;
}
