class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for (int x : nums) {
            int pos = lower_bound(dp.begin(), dp.end(), x) - dp.begin();

            if (pos == dp.size())
                dp.push_back(x);
            else
                dp[pos] = x;
        }

        return dp.size();
    }
};