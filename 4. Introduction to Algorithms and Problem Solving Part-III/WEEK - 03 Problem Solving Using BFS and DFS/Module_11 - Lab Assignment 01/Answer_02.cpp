#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj_list[N];
int visited[N];
int level[N];

void bfs(int src)
{
    queue<int>q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(auto nxt : adj_list[head])
        {
            if(visited[nxt] == 0){
                visited[nxt] = 1;
                level[nxt] = level[head] + 1;
                q.push(nxt);
            }

        }


    }

}

int main()
{
    int v, e;cin>>v>>e;

    for(int i=0; i<e; i++){
        int f, t;cin>>f>>t;
        adj_list[f].push_back(t);
    }

    bfs(0);

    for(int i=0; i<v; i++){
        cout<<"node "<<i<<"--> "<<"level: "<<level[i]<<endl;
    }

    return 0;
}
