class Solution {
public:
    bool isDivisible(int n, int t){
        int i = n;
        int product = 1;
        while(i > 0){
            int h = i % 10;
            product *= h;
            i /= 10;
        }
        return (product % t == 0);
    }
    int smallestNumber(int n, int t) {
        while(!isDivisible(n,t)){
            n++;
        }
        return n;
    }
};