class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); int m = image[0].size();
        queue<pair<int, int>> q;
        int curCol = image[sr][sc];

        if(curCol == color) return image;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr, sc});
        vector<pair< int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                image[x][y] = color;
                for(auto [dx, dy]: dirs){
                    int i = dx + x;
                    int j = y + dy;
                    if(i >= 0 && i < n && j >= 0 && j < m && image[i][j] == curCol && vis[i][j] == 0){
                        image[i][j] = color;
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        return image;
    }
};
