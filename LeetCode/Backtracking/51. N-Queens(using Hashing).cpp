class Solution {
public:
    vector<vector<string>>ans;
    
    
    void solve(int col, vector<string>&board, int n, vector<int>&leftRow, 
              vector<int>&upperDiagonal, vector<int>&lowerDiagonal){
        
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row =0; row<n; row++){
            if(leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n-1 + col - row]==0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                
                solve(col +1, board, n, leftRow, upperDiagonal, lowerDiagonal);
                
                //backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
            board[i] = s;
        
        vector<int>leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal);
        
        return ans;
    }
};
