class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); 
        int right = 0, left = n - 1;
        int maxArea = 0;
        while(right < left){
            maxArea = max(maxArea, (left - right) * min(height[left],height[right]));
            if(height[left] > height[right]){
                right++;
                // maxArea = max(maxArea, area);
            }
            else{
                left--;
                // maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};