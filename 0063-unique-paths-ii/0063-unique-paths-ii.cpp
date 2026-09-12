class Solution {
private:
    int rec(vector<vector<int>>& oG, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(oG[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = rec(oG, i, j - 1, dp);
        int up = rec(oG, i - 1, j, dp);
        return dp[i][j] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int i = oG.size();
        int j = oG[0].size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        int ans = rec(oG, i - 1, j - 1, dp);
        return ans;
    }
};