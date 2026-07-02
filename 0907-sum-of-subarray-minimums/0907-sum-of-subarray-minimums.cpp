class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res{};
        arr.push_back(-1);
        vector<int> st;
        st.reserve(arr.size());
        int MOD = 1e9+7;
        for (int i{}; i <arr.size(); ++i) {
            while (!st.empty() and arr[i] < arr[st.back()]) {
                int mid = st.back();
                st.pop_back();
                int left = st.empty()? -1 : st.back();
                int right = i;
                int contribution =  (right-mid) * (mid-left);
                // cout << "Number is " << arr[mid]<< ", contribution is " << contribution << "\n"; 
                res = (res + arr[mid] * static_cast<long long> (contribution)) % MOD;
            }
            st.push_back(i);
        }   
        return res;
    }
};