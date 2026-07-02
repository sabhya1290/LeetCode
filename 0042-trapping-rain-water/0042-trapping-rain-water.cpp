class Solution {
public:
    int trap(vector<int>& height) {
        int rMax = 0, lMax = 0, sum = 0;
        int left = 0; int right = height.size() - 1;
        while(left < right){
            if(height[left] <= height[right]){
                if(lMax > height[left]){
                    sum += lMax - height[left];
                }
                else lMax = height[left];
                left++;
            }
            else{
                if(rMax > height[right]){
                    sum += rMax - height[right];
                }
                else rMax = height[right];
                right--;
            }
        }
        return sum;
    }
};