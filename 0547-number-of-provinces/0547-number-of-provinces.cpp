class UF{
    vector<int> parent, size;
public:
    UF(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n + 1 ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findP(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findP(parent[node]);

    }

    bool unionBysize(int u, int v){
        int pu = findP(u);
        int pv = findP(v);

        if(pu == pv) return false;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        
        int n = isConnected.size();
        UF ufs(n);
        int province = n;

        for(int u = 0; u < n; u++){
            for(int v = u + 1; v < n; v++){
                if(isConnected[u][v] == 1){
                    if(ufs.unionBysize(u, v)) province--;
                }
            }
        }
        


        return province;
    }
};