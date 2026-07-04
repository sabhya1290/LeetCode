class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        for (auto& row : matrix) {
            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }
            maxArea = max(maxArea, maxHisto(height));
        }

        return maxArea;
    }
    int maxHisto(vector<int> histo){
        stack<int> st; 
        int ans = 0;
        int n = histo.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};