class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i){
        vis[i] = true;
        for(int it = 0; it < isConnected.size(); it++){
            if(isConnected[i][it] == 1 && !vis[it]){
                dfs(isConnected, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        int n = isConnected.size();
        int province = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                province++;
                dfs(isConnected, vis, i);
            }
        }
        return province;
    }
};