class Solution {
private:
    int rec(int n, vector<int>& dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = rec(n - 1, dp) + rec(n - 2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> ans(n + 1, -1);
        int b = rec(n, ans);
        return b;
    }
};