/*
C. Dijkstra?
============
https://codeforces.com/problemset/problem/20/C
Data : 01/ 04/ 2023
Phitron
*/

/* Normal Dijkstra TLE, we should use Optimized Dijkstra, which is using priority_queue.
v = 10^5
e = 10^5
max_w = 10^6

== 10^6 * 10^5 --> 10^11
so INF should 10^18

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long long int INF = 1e18;

vector<pair<int, int>>adj_list[N];

int visited[N], parent[N];
long long int d[N];

int v, e;

void optimized_dijkstra(int src)
{
    for(int i=1; i<=v; i++){
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue<pair<long long int, int>> pq;

    pq.push({0, src});

    while(!pq.empty())
    {
        pair<long long int, int>head = pq.top();
        pq.pop();

        int selected_node = head.second;

        if(visited[selected_node]==1) continue;
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(d[selected_node] + edge_cost < d[adj_node]){
                d[adj_node] = d[selected_node] + edge_cost;
                parent[adj_node] = selected_node;
                pq.push( {-d[adj_node], adj_node} );        //  [-] for Minimum wise Priority Queue.
            }
        }

    }


}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);


    cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int f, t, w;cin>>f>>t>>w;
        adj_list[f].push_back({t, w});
        adj_list[t].push_back({f, w});
    }

    int src = 1;
    optimized_dijkstra(src);

    if(visited[v]==0){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int>path;

    while(true)
    {
        if(v == 0){
            break;
        }
        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());
    for(auto x : path){
        cout<<x<<" ";
    }

    return 0;
}
