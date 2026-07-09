class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int indMax = 0;
        for(int i = 0; i < n; i++){
            if(indMax < i) return false;
            indMax = max(indMax, i + nums[i]);
        }
        return true;
    }
};