#include<bits/stdc++.h>
using namespace std;

int v, e;
const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>>adj_list[N];
int d[N], visited[N];



void dijkstra(int src)
{
    for(int i=1; i<v; i++)
    {
        d[i] == INF;
    }

    d[src] = 0;

    for(int i=0; i<v; i++)
    {
        int selected = -1;
        for(int j=1; j<=v; j++)
        {
            if(visited[j] == 1)continue;
            if(selected == -1 || d[selected] > d[j])
            {
                selected = j;
            }
        }
        visited[selected] = 1;

        for(auto adj_entry : adj_list[selected])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(d[selected] + edge_cost < d[adj_node]){
                d[adj_node] = d[selected] + edge_cost;
            }
        }
    }

}


int main()
{
    cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int f, t, w;
        cin>>f>>t>>w;
        adj_list[f].push_back( {t, w} );
        adj_list[t].push_back( {f, w} );
    }

    int src = 1;

    dijkstra(src);

    for(int i=1; i<=v; i++){
        cout<<d[i]<<" ";
    }

    return 0;
}
