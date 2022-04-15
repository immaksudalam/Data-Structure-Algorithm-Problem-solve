#include <bits/stdc++.h>
using namespace std;
int n;
int grid[1003][1003];
int dist[1003][1003];
int vis[1003][1003];
int dx4[] ={-1, 0, 1, 0};
int dy4[] ={0, 1, 0, -1};
vector<pair<int, int> >rareEle;
bool isSafe(int i, int j){
    return (i>=0 and i<n and j>=0 and j<n and grid[i][j]);
}
struct point{
    int x, y, level;
};
void bfs(int sx, int sy){
    queue<point>q;
    q.push({sx, sy, 0});
    
    while(!q.empty()){
        int ux = q.front().x;
        int uy = q.front().y;
        int ulevel = q.front().level;
        q.pop();
        
        for(int i=0; i<4; i++){
            int newx = dx4[i] + ux;
            int newy = dy4[i] + uy;
            if(isSafe(newx, newy)){
                if(ulevel + 1< dist[newx][newy]){
                    dist[newx][newy] = ulevel + 1;
                    q.push({newx, newy, dist[newx][newy]});
                }
            }
        }
    }
}
int main()
{
    cin>>n;
    int r; cin>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<r; i++){
        int x, y; 
        cin>>x>>y;
        x--, y--;
        rareEle.push_back({x, y});
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]){
                for(int k=0; k<n; k++){
                    fill(dist[k], dist[k]+n, INT_MAX);
                }
                bfs(i, j);
                int maxi = -1;
                for(int k=0; k<r; k++){
                    int x = rareEle[k].first;
                    int y = rareEle[k].second;
                    maxi = max(maxi, dist[x][y]);
                }
                if(maxi != INT_MAX){
                    ans = min(ans, maxi);
                }
            }
        }
    }
    cout<<ans<<endl;
}
