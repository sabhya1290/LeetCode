#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DJS { 
    vector<int> parent, size; 
public: 
    DJS(int n) { 
        parent.resize(n + 1); 
        size.resize(n + 1, 1); 
        for(int i = 0; i <= n; i++) { 
            parent[i] = i; 
        } 
    } 

    int findParent(int node) { 
        if(node == parent[node]) return node; 
        return parent[node] = findParent(parent[node]);
    } 

    void ubs(int u, int v) { 
        int pu = findParent(u); 
        int pv = findParent(v); 
        if(pu == pv) return; 

        if(size[pu] > size[pv]) { 
            parent[pv] = pu; 
            size[pu] += size[pv]; 
        } else { 
            parent[pu] = pv; 
            size[pv] += size[pu]; 
        } 
    } 
}; 

class Solution { 
public: 
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) { 
        unordered_map<string, int> mp; 
        int n = accounts.size(); 
        DJS ds(n); 

        for(int i = 0; i < n; i++) { 
            for(int j = 1; j < accounts[i].size(); j++) { 
                string mail = accounts[i][j]; 
                if(mp.find(mail) == mp.end()) { 
                    mp[mail] = i; 
                } else { 
                    ds.ubs(i, mp[mail]); 
                } 
            } 
        } 

        vector<vector<string>> mailvec(n);
        for(auto it : mp) { 
            string mail = it.first; 
            int node = ds.findParent(it.second); 
            mailvec[node].push_back(mail); 
        } 

        vector<vector<string>> ans; 
        for(int i = 0; i < n; i++) { 
            if(mailvec[i].empty()) { 
                continue; 
            } 
            
            sort(mailvec[i].begin(), mailvec[i].end()); 
            
            vector<string> temp; 
            temp.push_back(accounts[i][0]); 
            
            for(auto it : mailvec[i]) { 
                temp.push_back(it); 
            } 
            ans.push_back(temp); 
        } 
        return ans; 
    } 
};
