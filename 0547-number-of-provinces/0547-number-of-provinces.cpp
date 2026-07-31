class Solution {
public:
    void dfs(int currentCity, vector<bool>& visited, const vector<vector<int>>& isConnected) {
        visited[currentCity] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[currentCity][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, visited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) {
            return 0;
        }

        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                provinces++;
                dfs(i, visited, isConnected);
            }
        }

        return provinces;
    }
};