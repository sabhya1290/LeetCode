class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;        
        for(auto [x, y]: dirs){
            int i = row + x;
            int j = col + y;
            if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && vis[i][j] == 0 && board[i][j] == 'O'){
                dfs(board, vis, i, j);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                if(!vis[0][i])
                dfs(board, vis, 0, i);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[i][m - 1] == 'O'){
                if(!vis[i][m - 1])
                dfs(board, vis, i, m - 1);
            }
        }

        for(int i = m - 1; i >= 0; i--){
            if(board[n - 1][i] == 'O'){
                if(!vis[n - 1][i])
                dfs(board, vis, n - 1, i);
            }
        }

        for(int i = n - 1; i >= 0; i--){
            if(board[i][0] == 'O'){
                if(!vis[i][0])
                dfs(board, vis, i, 0);
            }
        }

        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};