class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        vector<int> in(n);

        for(auto it: pre){
            int u = it[0], v = it[1];
            adj[v].push_back(u);
            in[u]++;
        }
        
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(in[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        return cnt == n;
    }
};