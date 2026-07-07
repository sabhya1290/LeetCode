class Solution {
public:
    long long sumAndMultiply(int n) {
        long long nzd = 0;
        long long sum = 0;
        int i = n;
        int j = 0;
        while(i > 0){
            int t = i % 10;
            if(t != 0){
                sum += t;
                nzd += (t * pow(10, j));
                j++;
            }
            i = i / 10;
        }
        return nzd * sum;
    }
};