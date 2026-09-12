class Solution {
public:
    int rec(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int r = rec(m - 1, n, dp);
        int d = rec(m, n - 1, dp);
        return dp[m][n] = r + d;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0)); 
        // int ans = rec(m - 1, n - 1, dp);
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)continue;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};