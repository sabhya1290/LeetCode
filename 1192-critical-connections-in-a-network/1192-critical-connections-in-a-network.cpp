class Solution {
public:
    int time = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int> & vis, vector<int>& dt, vector<int> &lt, vector<vector<int>>& ans){
        vis[node] = 1;
        dt[node] = lt[node] = time;
        time++;
        for(auto& it: adj[node]){
            if(it == parent) continue;
            if(vis[it] != 1){
                dfs(it, node, adj, vis, dt, lt, ans);
                lt[node] = min(lt[node], lt[it]);
                if(lt[it] > dt[node]){
                    ans.push_back({it, node});
                }
            }
            else{
                lt[node] = min(lt[node], lt[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        vector<int> dt(n, 0);
        vector<int> lt(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, adj, vis, dt, lt, ans);
        return ans;
    }
};