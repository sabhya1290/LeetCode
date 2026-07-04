class Solution {
public:
    vector<int> nse(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> arr(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                arr[i] = st.top();
            }

            st.push(i);
        }

        return arr;
    }

    vector<int> pse(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> arr(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                arr[i] = st.top();
            }

            st.push(i);
        }

        return arr;
    }

    vector<int> nge(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> arr(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                arr[i] = st.top();
            }

            st.push(i);
        }

        return arr;
    }

    vector<int> pge(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> arr(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                arr[i] = st.top();
            }

            st.push(i);
        }

        return arr;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> n_se = nse(nums);
        vector<int> p_se = pse(nums);
        vector<int> n_ge = nge(nums);
        vector<int> p_ge = pge(nums);

        long long largest = 0;
        long long smallest = 0;

        for (int i = 0; i < n; i++) {
            long long maxCount =
                1LL * (i - p_ge[i]) * (n_ge[i] - i);

            long long minCount =
                1LL * (i - p_se[i]) * (n_se[i] - i);

            largest += maxCount * nums[i];
            smallest += minCount * nums[i];
        }

        return largest - smallest;
    }
};