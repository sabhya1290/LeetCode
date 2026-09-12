class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int i = oG.size();
        int j = oG[0].size();
        
        if (oG[0][0] == 1) return 0;
        
        vector<int> prev(j, 0);

        for(int m = 0; m < i; m++){

            vector<int> temp(j, 0);

            for(int n = 0; n < j; n++){

                if(m == 0 && n == 0) temp[n] = 1;

                else{
                    int up = 0, left = 0;
                    if(oG[m][n] == 0){
                    if(m > 0) up = prev[n];
                    if(n > 0) left = temp[n - 1];
                    }
                    temp[n] = up + left;
                }
            }
            prev = temp;
        }        
        return prev[j - 1];
    }

};