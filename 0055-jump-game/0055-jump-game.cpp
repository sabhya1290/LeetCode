class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int indMax = 0;
        for(int i = 0; i < n; i++){
            if(indMax == n - 1) return true;
            indMax = max(indMax, i + nums[i]);
        }
        return false;
    }
};