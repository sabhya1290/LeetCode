class Solution {
private:
    int rec(int n, vector<int> &v){
        if(n <= 2) return n;
        if(v[n] != -1) return v[n];
        return v[n] = rec(n - 1, v) + rec(n - 2, v);
    }
public:
    int climbStairs(int n) {
        vector<int> v(n + 1, -1);

        for(int i = 1; i < n + 1; i++){
            if(i == 1 || i == 2) v[i] = i;
            else{
                v[i] = v[i - 1] + v[i - 2];
            }
        }
        return v[n];
    }
};