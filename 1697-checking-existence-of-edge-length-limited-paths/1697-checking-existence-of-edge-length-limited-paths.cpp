class UnionFind{

    // parent , size
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        
        for(int i = 0;i <= n; i++){
            parent[i] = i;
        }
    }

    int parentFind(int x){
        if(x == parent[x]) return x;
        return parent[x] = parentFind(parent[x]);
    }

    void uf(int u, int v){
        int pu = parentFind(u);
        int pv = parentFind(v);

        if(pu == pv) return ;
        
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        int qsize = queries.size();
        vector<bool> ans(qsize, false);

        vector<vector<int>> indQue(qsize);
        for(int i = 0; i < qsize; i++){
            indQue[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2]; });

        sort(indQue.begin(), indQue.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2]; });

        UnionFind dsu(n);
        int edgeIdx = 0;

        for(int i = 0; i < qsize; i++){

            int u = indQue[i][0];
            int v = indQue[i][1];
            int lim = indQue[i][2];
            int idx = indQue[i][3];

            while(edgeIdx < edgeList.size() && edgeList[edgeIdx][2] < lim){
                dsu.uf(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
             
            if(dsu.parentFind(u) == dsu.parentFind(v)){
                ans[idx] = true;
            }
        }
        return ans;
    }
};