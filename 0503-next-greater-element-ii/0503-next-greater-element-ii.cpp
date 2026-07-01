class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(0); 
        int prev = st.top(); 
        vector<int> ans(n, -1);
        
        for(int i = 1 ; i < 2 * n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i % n]){
                prev = st.top();
                st.pop();
                ans[prev] = nums[i % n];
            }
            if(i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};