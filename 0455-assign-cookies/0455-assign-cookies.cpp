class Solution { // Author:- kaiHiwatari
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int givencount = 0;
        int L = 0;
        int R = 0;
        while(L < g.size() && R < s.size()){
            if(s[R] >= g[L]){
                givencount += 1;
                L++;
                R++;
            }else{
                R++;
            }
        }
        return givencount;
    }
};