class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int ls = 0;
        int rs = 0;
        vector<int> ans;
        vector<int> l;
        vector<int> r;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) {l.push_back(0); r.push_back(0);}
            else{
                ls += nums[i - 1];
                rs += nums[n - i];
                l.push_back(ls);
                r.push_back(rs);
            }
        }
        reverse(r.begin(), r.end());
        for(int i = 0; i < n; i++){
            int sum = abs(l[i] - r[i]);
            ans.push_back(sum);
        }
        return ans;
    }
};