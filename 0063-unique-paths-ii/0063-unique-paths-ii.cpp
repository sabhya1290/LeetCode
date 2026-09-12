class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int i = oG.size();
        int j = oG[0].size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        if (oG[0][0] == 1) return 0;
        for(int m = 0; m < i; m++){
            for(int n = 0; n < j; n++){
                if(m == 0 && n == 0) dp[m][n] = 1;
                else{
                    int up = 0, left = 0;
                    if(oG[m][n] == 0){
                    if(m > 0) up = dp[m - 1][n];
                    if(n > 0) left = dp[m][n - 1];
                    }
                    dp[m][n] = up + left;
                }
            }
        }        
        return dp[i - 1][j - 1];
    }

};