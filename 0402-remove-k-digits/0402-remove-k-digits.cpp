class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k) return "0";
        stack<char> st;
        string ans = "";
        int cnt = 0;
        for(char s: num){
            while(!st.empty() && k > 0 && st.top() > s){
                st.pop();
                k--;
            }
            st.push(s); 
        }
        while(!st.empty() && k > 0) {   
            st.pop(); 
            k--; 
        }
        
        if(st.empty()) return "0";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.size() > 0 && 
              ans.back() == '0') {

            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        
        if(ans.empty()) return "0";
        return ans;
    }
};