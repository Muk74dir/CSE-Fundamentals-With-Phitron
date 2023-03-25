/*

Graph Coloring
==============

Problem :  #Building Teams :  https://cses.fi/problemset/task/1666
==================================================================


Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2

Graph Representation :
======================


(1)      (2)
 1<------>2
 |
 |             (1)       (2)
 3(2)           4<------->5



*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int visited[N];

int color[N];

vector<int>adj_list[N];


bool dfs(int src)
{

    visited[src] = 1;

    for(auto adj_node : adj_list[src])
    {
        if(visited[adj_node] == 0){

            //assigning different color
            if(color[src] == 1)color[adj_node] = 2;
            else color[adj_node] = 1;

            bool is_bicolorable = dfs(adj_node);
            if(!is_bicolorable){
                return false;
            }
        }

        else{
            if(color[src] == color[adj_node]) return false;
        }
    }

    return true;
}


int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
        adj_list[t].push_back(f);
    }

    for(int i=1; i<=v; i++)
    {
        if(visited[i] == 0){
            color[i] = 1; // color 1 & 2;
            bool ok = dfs(i);
            if(!ok){
                 cout<<"IMPOSSIBLE";
                 return 0;
            }
        }
    }

    for(int i=1; i<=v; i++){
        cout<<color[i]<<" ";
    }

    return 0;
}
