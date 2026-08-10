class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // step 1
        int maxRow = 0; 
        int maxCol = 0;
        for(auto &it: stones){
            maxRow = max(it[0], maxRow);
            maxCol = max(it[1], maxCol);
        }

        // step 2
        DisjointSet ds(maxRow + maxCol + 1);
        // unordered_map<int, int> mp;

        for(auto &it: stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            
            ds.unionBySize(row, col);
            // mp[row] = 1;
            // mp[col] = 1;
        }

        // step 3
        // int cnt = 0;
        unordered_set<int> st;
        
        // for(auto& it: mp){
        //     if(ds.findParent(it.first) == it.first) cnt++;
        // }

        for(int i = 0; i < n; i++){
            st.insert(ds.findParent(stones[i][0]));
        }

        return stones.size() - st.size();
    }
};