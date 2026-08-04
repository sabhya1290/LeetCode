class Solution {
public:

    bool dfs(int src, vector<vector<int>>& graph, vector<int>& state) {
        if (state[src] == 1) { // cycle found
            return false;
        }
        if (state[src] == 2) { // already known safe
            return true;
        }

        state[src] = 1; // mark as visiting

        for (int v : graph[src]) {
            if (!dfs(v, graph, state)) {
                return false;
            }
        }

        state[src] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;

        for (int i=0; i<n; i++) {
            if (dfs(i, graph, state)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};