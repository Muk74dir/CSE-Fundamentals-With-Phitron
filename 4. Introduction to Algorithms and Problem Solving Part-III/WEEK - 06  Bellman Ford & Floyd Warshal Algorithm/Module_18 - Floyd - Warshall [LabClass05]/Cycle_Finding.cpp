/* Cycle Finding : https://cses.fi/problemset/task/1197
======================================================= */

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9;
const int N = 1e5+5;

vector<pair<int, int>>adj_list[N];
long long parent[N];
long long d[N];


int main()
{
    int n, m;cin>>n>>m;

    for(int i=1; i<=n; i++){
        d[i] = INF;
    }

    for(int i=0; i<m; i++){
        int u, v, w;cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
    }

    bool neg_cy = false;
    int last_updated = -1;

    for(int i=1; i<=n; i++){
        for(int node = 1; node<=n; node++){
            for(pair<int, int>adj_node : adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    parent[v] = u;

                    if(i == n){
                        neg_cy = true;
                        last_updated = v;
                    }
                }
            }
        }
    }


    if(neg_cy){
        cout<<"YES\n";
        int selected = last_updated;
        for(int i=1; i<=n-1; i++){
            selected = parent[selected];
        }

        int first_node = selected;

        vector<int>cycle_path;
        cycle_path.push_back(selected);

        while (true){
            selected = parent[selected];
            cycle_path.push_back(selected);
            if(selected == first_node){
                break;
            }
        }

        reverse(cycle_path.begin(), cycle_path.end());
        for(int x : cycle_path){
            cout<<x<<" ";
        }

    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
