class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it: graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safestate;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            safestate.push_back(node);
            q.pop();
            for(auto it: revGraph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safestate.begin(), safestate.end());
        return safestate;
    }
};