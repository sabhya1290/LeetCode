class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int i = 0;

        while (i < num.size()) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
            i++;
        }

    
        while (k > 0) {
            st.pop();
            k--;
        }

        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

   
        i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if (res == "")
            return "0";

        return res;
    }
};