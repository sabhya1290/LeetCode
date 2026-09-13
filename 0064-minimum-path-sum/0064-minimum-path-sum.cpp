class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(i||j)
                    g[i][j]+=min(i?g[i-1][j]:1e9,j?g[i][j-1]:1e9);
        return g[m-1][n-1];
    }
};