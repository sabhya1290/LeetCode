class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),ans = 0 ;
        stack<int> st; 
        for(int i = 0 ; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int mid = st.top();
                st.pop();
                int left = st.empty()? -1 : st.top();
                left = i - left-1; 
                ans = max(ans, left*heights[mid]);
            }
            st.push(i);
        }
        return ans ;
    }
};