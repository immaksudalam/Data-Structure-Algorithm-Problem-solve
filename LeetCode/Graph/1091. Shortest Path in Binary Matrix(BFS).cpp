class Solution {
public:
    int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        map<pair<int, int>, int>level;
        queue<pair<int, int>>q;
        int n = grid.size();
        int visited[n][n];
        for(int i=0; i<n; i++)
            for(int j =0; j<n; j++) visited[i][j] = -1;
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)  return -1;
        
        q.push({0, 0});
        level[{0, 0}] = 1;
        int cnt = 0;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int i=0; i<8; i++){
                int xx = a + x[i];
                int yy = b + y[i];
                if((xx>=0 && xx<n && yy>=0 && yy<n) && visited[xx][yy] == -1 && grid[xx][yy]==0){
                    visited[xx][yy] = 1;
                    level[{xx, yy}] = level[{a, b}] + 1;
                    q.push({xx, yy});
                }
            }
        }
       
        if(level[{n-1, n-1}]) return level[{n-1, n-1}];
        return -1;
    }
};
