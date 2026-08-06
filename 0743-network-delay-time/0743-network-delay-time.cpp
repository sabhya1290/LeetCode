class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
        q.push({0, k});
        dis[k] = 0;

        while(!q.empty()){
            auto [time, node] = q.top();
            q.pop();

            if(time > dis[node]) continue;

            for(auto it: adj[node]){

                int nextNode = it.first;
                int wt = it.second;
                
                if(dis[nextNode] > wt + time){
                    dis[nextNode] = wt + time;
                    q.push({dis[nextNode], nextNode});
                }

            }
        }

        int maxTime = 0;
        for(int i = 1; i < n + 1; i++){
            if(dis[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dis[i]); 
        }
        return maxTime;
    }
};