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
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        int ans = rec(m - 1, n - 1, dp);
        return ans;
    }
};