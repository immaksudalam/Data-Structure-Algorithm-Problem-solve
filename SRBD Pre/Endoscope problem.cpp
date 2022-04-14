#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, l;
int grid[1001][1001];
int vis[1001][1001], dist[1001][1001];
int dx[][4] = {
    {-1, 0, 1, 0},
    {-1, 1, 0, 0},
    {0, 0, 0, 0},
    {-1, 0, 0, 0},
    {0, 1, 0 , 0},
    {1, 0, 0, 0},
    {-1, 0, 0, 0}
};
int dy[][4] = {
    {0, 1, 0, -1},
    {0, 0, 0, 0},
    {1, -1, 0, 0},
    {0, 1, 0, 0},
    {1, 0, 0, 0},
    {0, -1, 0, 0},
    {0, -1, 0, 0}

};
bool isSafe(int x, int y){
    if(x< 0 || x>=n || y<0 || y>=m || vis[x][y]==1 || grid[x][y] == 0) return false;
    return true;
}
void solve(){
    cin>>n>>m>>sx>>sy>>l;
    for(int i=0; i<n; i++)
      for(int j = 0; j<m; j++){
          cin>>grid[i][j];
      }
    queue<pair<int, int>>q;
    if(grid[sx][sy]){
        q.push({sx, sy});
        vis[sx][sy] = 1;
        dist[sx][sy] = 0;
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int id = grid[x][y];
        if(id){
            id--;
            for(int i=0; i<4; i++){
                int newx = x + dx[id][i];
                int newy = y + dy[id][i];
                if(isSafe(newx, newy)){
                    int newId = grid[newx][newy] - 1;
                    bool ok = false;
                    for(int j=0; j<4; j++){
                        int revNewx = newx + dx[newId][j];
                        int revNewy = newy + dy[newId][j];
                        if(revNewx == x && revNewy == y){
                            ok = true;
                            break;
                        }
                    }
                    if(ok){
                        vis[newx][newy] = 1;
                        q.push({newx, newy});
                        dist[newx][newy] = dist[x][y] + 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]){
                if(dist[i][j] < l){
                    ans++;
                }
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
   int t; 
   cin>>t;
   while(t--){
       solve();
   }
   return 0;
}
