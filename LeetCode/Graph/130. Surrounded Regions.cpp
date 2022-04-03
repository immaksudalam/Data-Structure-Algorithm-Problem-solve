class Solution {
public:
    vector<pair<int, int>>temp;
    int visited[201][201];
    bool helper(vector<vector<char>>&board, int i, int j){
        if(i<0 || i>= board.size() || j<0 || j>= board[0].size()) return false;
        if(board[i][j] == 'X') return true;
        if(visited[i][j] == 1) return true;
        temp.push_back({i, j});
        visited[i][j] = 1;
        
        bool a = true, b = true, c = true, d = true;
         a = helper(board, i+1, j);
         b = helper(board, i-1, j);
         c = helper(board, i, j+1);
         d = helper(board, i, j-1);
        
        return a && b && c && d;
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++) visited[i][j] = -1;
        
        for(int i =0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O' && visited[i][j] == -1){
                    bool flag = helper(board, i, j);
                    if(flag){
                        for(int k = 0; k<temp.size(); k++){
                            int a = temp[k].first;
                            int b = temp[k].second;
                            board[a][b] = 'X';
                        }
                    }
                    temp.clear();
                }
            }
        }
    }
};
