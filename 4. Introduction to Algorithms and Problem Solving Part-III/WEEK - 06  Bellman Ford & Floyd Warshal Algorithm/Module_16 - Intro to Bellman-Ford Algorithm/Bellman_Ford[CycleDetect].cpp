#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 5;

vector<pair<int, int>>adj_list[N];
int d[N];


int main()
{
    int v, e;cin>>v>>e;

    for(int i=1; i<=v; i++){
        d[i] = INF;
    }

    for(int i=0; i<e; i++){
        int f, t, w;cin>>f>>t>>w;
        adj_list[f].push_back({t, w});
    }

    int src = 1;
    d[src] = 0;

    bool negative_cycle = false;

    for(int i=1; i<=v; i++){
        for(int node=1; node<=v; node++){
            for(pair<int, int>adj_node : adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;


                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    if( i == v){
                        negative_cycle = true;
                    }
                }
            }
        }
    }

    if(negative_cycle == true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
