class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, -1, 1};

    bool check(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.back().size();
    
        vector<vector<int>>dst(n, vector<int>(m, INT_MAX));
        dst[0][0] = 0;

        queue<pair<int, int>>q;
        q.push({0, 0});
        while(q.size()) {
            int cr = q.front().first, cc = q.front().second;
            q.pop();

            for(int d=0;d<8;d++) {
                int nxr = cr + dx[d], nxc = cc + dy[d];
                int nxDst = dst[cr][cc] + 1;

                if(check(nxr, nxc, n, m) && grid[nxr][nxc] == 0 && nxDst < dst[nxr][nxc]) {
                    dst[nxr][nxc] = nxDst;
                    q.push({nxr, nxc});
                }
            }
        }

        return ((grid[0][0]==1 || dst[n-1][m-1]==INT_MAX)? -1: dst[n-1][m-1]+1);
    }
};