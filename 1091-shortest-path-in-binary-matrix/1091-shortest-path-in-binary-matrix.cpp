class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;
        if (grid[0][0] == 0 && grid.size() == 1 && grid[0].size() == 1)
            return 1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 0;
        queue<pair<int, int>> q;
        int targetX = n - 1;
        int targetY = n - 1;
        
        int dx[] = {1, -1, 0, 1, 0, -1, -1, 1};
        int dy[] = {1, -1, 1, 0, -1, 0, 1, -1};


        int cnt = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int N = q.size(); 
            for (int i = 0; i < N; i++) {
                int x = q.front().first;
                int y = q.front().second;
                int pD = dis[x][y]; 
                q.pop();
                
                for (int d = 0; d < 8; d++) {
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    
                    if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                        grid[newX][newY] == 0 && pD + 1 < dis[newX][newY]) {
                        if (newX == targetX && newY == targetY)
                            return pD + 2;
                            
                        q.push({newX, newY});
                        dis[newX][newY] = pD + 1; 
                    }
                }
            }
        }
        
        return -1;
    }
};