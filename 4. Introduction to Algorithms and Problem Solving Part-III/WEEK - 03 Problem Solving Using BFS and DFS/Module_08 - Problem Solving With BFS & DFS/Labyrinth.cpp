#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
int maze[N][N], visited[N][N];
int level[N][N];

pair<int, int>src, dst;
int n, m;
string dir = "";

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool is_notvisited(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(visited[x][y] == 0){
        return true;
    }
    return false;
}

bool is_safe(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y] == -1){
        return false;
    }
    return true;
}

bool is_inside(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(x>=0 && x<n &&  y>=0 && y<m){
        return true;
    }
    return false;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>>q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while(!q.empty())
    {
        pair<int, int>head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;


        for(int i=0; i<4; i++)
        {

            int new_x = x+ dx[i];
            int new_y = y+ dy[i];
            pair<int, int>adj_node = {new_x, new_y};
            if(is_inside(adj_node) && is_safe(adj_node) && is_notvisited(adj_node)){
                if(i == 0){
                    dir += 'R';
                }
                else if(i== 1){
                    dir += 'L';
                }
                else if(i == 2){
                    dir += 'D';
                }
                else if(i == 3){
                    dir += 'U';
                }
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}


int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            level[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<m; j++){

            if(input[j] == '#'){
                maze[i][j] = -1;
            }
            else if(input[j] == 'A'){
                src = {i, j};
            }
            else if(input[j] == 'B'){
                dst = {i, j};
            }
        }
    }

    bfs(src);

    if(level[dst.first][dst.second] == -1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<level[dst.first][dst.second]<<"\n";
        cout<<dir.substr(0, (level[dst.first][dst.second]))<<"\n";
    }
    return 0;
}
