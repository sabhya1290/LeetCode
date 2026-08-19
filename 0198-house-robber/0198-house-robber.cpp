class Solution {
private:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        
        if (n < 0) return 0;
        if (n == 0) return nums[0];
        
        if(dp[n] != -1) return dp[n];
        
        int left = nums[n] + solve(nums, n - 2, dp);
        int right = solve(nums, n - 1, dp);
        
        return dp[n] = max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, -1);
        int ans = solve(nums, n - 1, dp);
        return ans;
    }
};