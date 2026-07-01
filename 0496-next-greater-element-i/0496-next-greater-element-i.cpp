class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        ;
        stack<int> helperStack;
        for (int i = n - 1; i >= 0; i--) {
            int currentElement = nums2[i];

            // if the stack is empty->no greater element
            if (helperStack.empty()) {
                ans[i] = -1;
                helperStack.push(currentElement);
                continue;
            }

            // if top element of the stack is > nums2[i] then it is the next
            // greater element
            if (helperStack.top() > currentElement) {
                ans[i] = helperStack.top();
                helperStack.push(currentElement);
                continue;
            }

            // remove all stack elements which are smaller than currentElement.
            while (!helperStack.empty() && helperStack.top() < currentElement) {
                helperStack.pop();
            }

            // if stack becomes empty after popping all smaller elements, then
            // perform these three operations
            if (helperStack.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = helperStack.top();
            }
            helperStack.push(currentElement);
        }
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = ans[i];
        }

        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(mp[nums1[i]]);
        }

        return result;
    }
};