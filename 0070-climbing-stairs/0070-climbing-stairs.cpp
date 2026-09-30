class Solution {
private:
    int rec(int n, vector<int> &v){
        if(n <= 2) return n;
        if(v[n] != -1) return v[n];
        return v[n] = rec(n - 1, v) + rec(n - 2, v);
    }
public:
    int climbStairs(int n) {
        vector<int> vec(n + 1, -1);

        int ans = rec(n, vec); 
        return ans;
    }
};