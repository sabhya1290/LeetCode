class Solution {
private:
// Recurstion + memoization
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
        // int ans = solve(nums, n - 1, dp);
        // return ans;

        if (n == 1) return nums[0];

        // vector<int> dp(n, -1);

        // dp[0] = nums[0];
        // dp[1] = max(nums[1], nums[0]);

        // Tabulation
        // for(int i = 2; i < n; i++){
        //     int pick = nums[i] + dp[i - 2];
        //     int notpick = dp[i - 1];

        //     dp[i] = max(pick, notpick);
        // }
        // return dp[n - 1];

// Space Optimization
        int prev = nums[0];
        int prev2 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int pick = nums[i] + prev;
            int notp = prev2;

            int cur = max(pick, prev2);
            prev = prev2;
            prev2 = cur;
        }
        return prev2;
    }
};