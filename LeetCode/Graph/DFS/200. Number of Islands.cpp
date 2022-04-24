class Solution {
public:
    void helper(vector<vector<char>>&grid, int sr, int sc, int m, int n){
        if(sr<0 || sr>=m || sc<0 || sc>=n) return;
        if(grid[sr][sc] != '1') return;
        
        grid[sr][sc]='3';
        
        helper(grid, sr+1, sc, m, n);
        helper(grid, sr-1, sc, m, n);
        helper(grid, sr, sc+1, m, n);
        helper(grid, sr, sc-1, m, n);
        helper(grid, sr, sc, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    helper(grid, i, j, m, n);
                }
            }
        
        return ans;
    }
};
