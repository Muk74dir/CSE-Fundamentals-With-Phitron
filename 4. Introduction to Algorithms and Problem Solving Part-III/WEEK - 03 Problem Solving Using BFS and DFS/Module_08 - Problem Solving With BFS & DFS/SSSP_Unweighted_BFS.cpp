#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
int level[N];

vector<int>adj_list[N];

void BFS(int src)
{
    queue<int>q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(auto nxt_node : adj_list[head])
        {
            if(visited[nxt_node] == 0){
                visited[nxt_node] = 1;
                level[nxt_node] = level[head] + 1;
                q.push(nxt_node);
            }
        }
    }
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


    int src=0;
    BFS(src);

    for(int i=0; i<v; i++){
        cout<<"NODE "<<i<<" Level is "<<level[i]<<endl;
    }

    return 0;
}

/*

    Example Graph
    =============
    (0)    (1)     (2)
     0..... 1.......2.......3 (3)
            |       |
            |       |
         (2)5.......4(3)

INPUT :

6 6

0 1
2 3
1 5
1 2
2 4
5 4

*/
