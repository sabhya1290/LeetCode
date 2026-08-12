class Solution {
public:
    int n;
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0;

        if (grid[r][c] != 1)
            return 0;

        grid[r][c] = id;
        int size = 1;
        size += dfs(grid, r + 1, c, id);
        size += dfs(grid, r - 1, c, id);
        size += dfs(grid, r, c + 1, id);
        size += dfs(grid, r, c - 1, id);

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();
        unordered_map<int, int> islandsize;
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, id);
                    islandsize[id] = size;
                    id++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    continue;

                set<int> uniqueislands;

                if (i > 0 && grid[i - 1][j] > 1) {
                    uniqueislands.insert(grid[i - 1][j]);
                }

                if (i + 1 < n && grid[i + 1][j] > 1) {
                    uniqueislands.insert(grid[i + 1][j]);
                }

                if (j > 0 && grid[i][j - 1] > 1) {
                    uniqueislands.insert(grid[i][j - 1]);
                }

                if (j + 1 < n && grid[i][j + 1] > 1) {
                    uniqueislands.insert(grid[i][j + 1]);
                }

                int currsize = 1;
                for (int islands : uniqueislands) {
                    currsize += islandsize[islands];
                }

                ans = max(ans, currsize);
            }
        }

        if (ans == 0) {
            return n * n;
            
        }

        return ans;
    }
};