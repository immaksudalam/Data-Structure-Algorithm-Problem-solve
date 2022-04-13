#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool isValid(int i, int j){
    //cout<<"True"<<endl;
    if(i<0 || i>=n || j<0 || j>=n) return false;
    return true;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int value, vector<vector<int>>&grid,
vector<vector<int>>&path, vector<vector<int>>&vis){
    if(x== n-1 && y == n-1){
        if(value >= ans){
            ans = value;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(vis[i][j]) path[i][j] = 3;
                    else path[i][j] = grid[i][j];
                }
            }
        }
        return;
    }
    
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(isValid(xx, yy)){
            //check for path
            if(vis[xx][yy] == 0 && grid[xx][yy] == 0){
                vis[xx][yy] = 1;
                dfs(xx, yy, value, grid, path, vis);
                vis[xx][yy] = 0; // backtrack
            }
            //check for juel
            if(vis[xx][yy] == 0 && grid[xx][yy] == 2){
                vis[xx][yy] = 1;
                dfs(xx, yy, value+1, grid, path, vis);
                vis[xx][yy] = 0; //backtrack;
            }
        }
    }
}
void PrintPath(vector<vector<int>>&path){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<path[i][j]<<" ";
        }cout<<endl;
    }
}
int main()
{
    n;
    cin>>n;
    vector<vector<int>>grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>grid[i][j];
    }
    vector<vector<int>>vis(n, vector<int>(n, 0));
    vector<vector<int>>path(n, vector<int>(n, 0));
    ans = INT_MIN;
    vis[0][0] = 1;
    if(grid[0][0] == 2){
        dfs(0, 0, 1, grid, path, vis);
    }
    else{
        dfs(0, 0, 0, grid, path, vis);
    }
    cout<<"path traverse"<<endl;
    PrintPath(path);
    cout<<"Total juel found: "<<ans<<endl;
}
