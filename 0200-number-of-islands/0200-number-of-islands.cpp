class Solution {

private:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        grid[i][j] = '0';
        for(auto [x, y]: dirs){
            
            int row = i + x;
            int col = j + y;

            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1' ){
                dfs(grid, vis, row, col);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n ,vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' ){
                    cnt++;
                    dfs(grid, vis, i , j);
                }
            }
        }
        return cnt;
    }
};