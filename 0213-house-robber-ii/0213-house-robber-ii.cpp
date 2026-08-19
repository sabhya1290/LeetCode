class Solution {
private:
    int robsolve(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
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
public:
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        int ans1 = robsolve(temp1);
        int ans2 = robsolve(temp2);
        
        return max(ans1, ans2);
    }
};