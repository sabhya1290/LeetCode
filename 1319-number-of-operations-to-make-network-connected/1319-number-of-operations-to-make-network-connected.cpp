class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> parent(n);
        vector<int> size(n, 1);
        
        for (int i = 0; i < n; i++) parent[i] = i;

        int components = n;

        for (const auto& edge : connections) {
            int pu = findParent(edge[0], parent);
            int pv = findParent(edge[1], parent);

            if (pu != pv) {
                if (size[pu] < size[pv]) {
                    parent[pu] = pv;
                    size[pv] += size[pu];
                } else {
                    parent[pv] = pu;
                    size[pu] += size[pv];
                }
                components--; 
            }
        }

        return components - 1;
    }
};
