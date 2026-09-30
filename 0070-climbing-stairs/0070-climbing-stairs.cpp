class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int cur = 1;
        // int next = 0;

        for(int i = 2; i < n + 1; i++){
            int next = cur + prev;
            cur = prev;
            prev = next;
        }
        return prev;
    }
};