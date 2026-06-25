class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int>& nums, int K) {
        int left = 0;
        unordered_map<int,int> frq;
        int res = 0;
        
        for(int right = 0; right < nums.size(); right++){
            if (frq[nums[right]] == 0) {
                K--;
            }
            frq[nums[right]]++;
            
            while(K < 0){
                frq[nums[left]]--;
                if(frq[nums[left]] == 0){
                    K++;
                }
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
};