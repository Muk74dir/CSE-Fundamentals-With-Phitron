/*

Flood Fill
==========


Problem : Counting Rooms : https://cses.fi/problemset/task/1192
===============================================================


Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2002;

int maze[N][N], visited[N][N];

int r, c;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_notvisited(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(visited[x][y] != 1){
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] != -1){
        return true;
    }
    return false;
}


bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(x>=0 && x<r && y>=0 && y<c){
        return true;
    }
    return false;
}


void bfs(pair<int, int>src)
{
    queue< pair<int, int> > q;
    visited[src.first][src.second] = 1;

    q.push(src);

    while(!q.empty())
    {
        pair<int, int>head = q.front();

        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && is_notvisited(adj_node)){
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }


        }

    }
}

pair<int, int> unvisited_finder()
{
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(visited[i][j] == 0 && maze[i][j] == 0)
                return {i, j};
        }
    }

    return {-1, -1};

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c;
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            if(temp[j] == '#'){
                maze[i][j] = -1;
            }
        }
    }

    int cnt = 0;
    while(true)
    {
        pair<int, int>unvistied_position = unvisited_finder();
        if(unvistied_position == pair<int, int>(-1, -1)){
            break;
        }
        cnt++;
        bfs(unvistied_position);

    }

    cout<<cnt<<"\n";
    return 0;
}
