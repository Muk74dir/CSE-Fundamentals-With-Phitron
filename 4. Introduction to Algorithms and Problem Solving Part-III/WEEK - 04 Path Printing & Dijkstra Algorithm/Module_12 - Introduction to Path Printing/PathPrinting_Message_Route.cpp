/*

Path Printing
=============

Problem : #Message Route : https://cses.fi/problemset/task/1667
===============================================================

Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5


*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj_list[N];
int visited[N], level[N], parent[N];

void bfs(int src)
{
    queue<int>q;

    visited[src] = 1;
    level[src] = 1; // source node = A , destination node = A , path length will be 1;
    parent[src] = -1;

    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto nxt : adj_list[head]){
            if(visited[nxt] == 0){
                level[nxt] = level[head] + 1;
                visited[nxt] = 1;

                parent[nxt] = head;

                q.push(nxt);
            }
        }
    }
}

int main()
{
    vector<int>path;

    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
        adj_list[t].push_back(f);
    }

    int src = 1;
    bfs(src);

    int dest = v;

    if(visited[dest] == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<level[dest]<<"\n";

    while(true)
    {
        path.push_back(dest);
        dest = parent[dest];
        if(dest == -1){
            break;
        }
    }

    reverse(path.begin(), path.end());

    for(auto x : path){
        cout<<x<<" ";
    }

    return 0;
}
