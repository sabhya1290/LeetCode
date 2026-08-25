class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
       int ans=0;
       for(int i=0;i<points.size();i++){
        unordered_map<int,int>freq;
        for(int j=0;j<points.size();j++){
            if(i==j) continue;
            int dx=points[i][0]-points[j][0];
            int dy=points[i][1]-points[j][1];

            int dist=dx*dx+dy*dy;
            ans+=2*freq[dist];
            freq[dist]++;
        }
       }
       return ans; 
    }
};