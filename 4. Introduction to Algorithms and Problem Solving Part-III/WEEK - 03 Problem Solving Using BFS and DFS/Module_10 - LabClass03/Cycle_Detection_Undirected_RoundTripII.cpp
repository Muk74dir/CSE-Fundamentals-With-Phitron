/*

Cycle Detection
===============

Problem : #Round Trip II : https://cses.fi/problemset/task/1678
================================================================

Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2


*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

bool dfs_DetectCycle(int src)
{
    visited[src] = 1;

    for(auto adj_node : adj_list[src])
    {
        if(visited[adj_node] == 0){
            bool got_cylcle = dfs_DetectCycle(adj_node);
            if(got_cylcle){
                return true;
            }
        }

        else if(visited[adj_node] == 1){
            return true;
        }
    }

    visited[src] = 2;
    return false;
}

int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
    }

    bool cycle_exist = false;

    for(int i=0; i<v; i++){
        if(visited[i] == 0){
            bool is_cyclic = dfs_DetectCycle(i);
            if(is_cyclic){
                cycle_exist == true;
                break;
            }
        }
    }
    if(cycle_exist){
        cout<<"Cycle Exist";
    }
    else
        cout<<"IMPOSSIBLE";



    return 0;
}

