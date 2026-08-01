class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis = grid;
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;

        int min = -1;
        vector<pair<int, int>> dir = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            int size = q.size();
            while(size){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy]: dir){
                    int i = dx + x;
                    int j = y + dy;
                    if(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 1){
                        fresh--;
                        vis[i][j] = 2;
                        q.push({i, j});
                    }
                }
                size--;
            }
            min++;
        }
        if(fresh) return -1;
        return min;
    }
};