class Solution {

private:

    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        
        vis[row][col] = 1;

        for(auto [x, y]: dirs){
            
            int i = row + x;
            int j = col + y;
            
            if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1 && !vis[i][j])

            dfs(grid, vis, i, j);

        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(grid, vis, 0, i);
            }
            if(grid[n - 1][i] == 1 && !vis[n - 1][i]){
                dfs(grid, vis, n - 1, i);
            }
        }
        for(int i = 0; i < n; i++){
            if(grid[i][m - 1] == 1 && !vis[i][m - 1]){
                dfs(grid, vis, i, m - 1);
            }
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(grid, vis, i, 0);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};