class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state)
    {
        state[node]= 1;
        for(int nei:adj[node])
        {
            if(state[nei]== 1)
            {
                return false;
            }
            if(state[nei]== 0)
            {
                if(!dfs(nei, adj, state))
                {
                    return false;
                }
            }
        }
            state [node]= 2;
            return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        for(auto &p: prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }    
        vector<int> state(numCourses, 0);
        for(int i= 0; i< numCourses; i++)
        {
            if(state[i]== 0)
            {
                if(!dfs(i, adj, state))
                {
                    return false;
                }
            }
        }
        return true;
    }
};