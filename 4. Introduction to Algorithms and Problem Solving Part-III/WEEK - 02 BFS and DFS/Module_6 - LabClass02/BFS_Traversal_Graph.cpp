#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int>adj_list[N];

void BFS(int src)
{
    queue<int>q;
    visited[src] = 1;
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        cout<<head<<" ";

        for(int adj_node : adj_list[head])
        {
             if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                q.push(adj_node);
             }
        }
    }

}

 /*

    Example Graph
    =============

     0......1.......2.......3
            |       |
            |       |
            5.......4

    Vertex = 6
    Edge = 6

    Adjacent Node List :
    0 --> 1
    1 --> 2
    2 --> 3
    1 --> 5
    2 --> 4
    5 --> 4

 */


int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int a, b;cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src = 0;
    cout<<"TRAVERSE's NODES : ";
    BFS(src);


    return 0;
}

/*
INPUT:          OUTPUT:
6 6
0 1
2 3             TRAVERSE's NODES : 0 1 5 2 4 3
1 5
2 4
5 4
1 2

*/
