class Solution {
public:
    bool dfs(string& s,int i,unordered_map<string,bool>& x,vector<int>& y){
        if(i==s.length() || y[i]==2) return true;
        if(y[i]==1) return false;
        string t="";
        int j=i;
        while(i<s.length()){
            t+=s[i];
            i++;
            if(x.find(t)!=x.end() && dfs(s,i,x,y)){
                y[j]=2;
                return true;
            }
        }
        y[j]=1;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> x;
        int n=wordDict.size();
        vector<int> y(s.length(),-1);
        for(int i=0;i<n;i++){
            x[wordDict[i]]=1;
        }
        return dfs(s,0,x,y);
    }
};