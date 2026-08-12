class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();

        unordered_map<int,int> mp;
        mp[0]=-1;

        int idx=-1, cnt=0;

        long long sum=0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];

            long long T = sum-target;

            if(mp.find(T) != mp.end()) {
                if(mp[T] >= idx) {
                    idx = i;
                    cnt++;
                    sum=0;
                }
            }

            mp[sum]=i;
        }
        
        return cnt;
    }
};