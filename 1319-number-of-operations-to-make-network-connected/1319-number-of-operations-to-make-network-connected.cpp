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

    bool unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;
        
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet DS(n);

        int cnt = 0;
        int con = 0;
        
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            
            if(DS.unionBySize(u, v)) cnt++;
            else con++;

        }

        if(cnt + con >= n - 1) return n - cnt - 1;
        return -1;
    }
};