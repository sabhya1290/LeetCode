class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i <  0 || j < 0) return INT_MAX - 1000;
        
        if(dp[i][j] != -1 ) return dp[i][j];

        int up = grid[i][j] + rec(i - 1, j, grid, dp);
        int left = grid[i][j] + rec(i , j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int mini = INT_MAX;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int s = grid[i][j];
                    int up = s, left = s;
                    if(i > 0) up += dp[i - 1][j];
                    else up =  1e9;
                    if(j > 0) left += dp[i][j - 1];
                    else left =  1e9;

                    dp[i][j] = min(up, left);
                }

            }
        }

        return dp[m - 1][n - 1];
    }
};