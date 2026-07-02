class Solution {
private:
    vector<int> nextSmallestElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

    vector<int> prevSmallestElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            pse[i] = st.top();
        }

        st.push(i);
    }

    return pse;
}

public:
    int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    vector<int> nse = nextSmallestElement(arr);
    vector<int> pse = prevSmallestElement(arr);

    long long total = 0;

    for (int i = 0; i < arr.size(); i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;

        total = (total + (left * right % MOD) * arr[i]) % MOD;
    }

    return total;
}
};
