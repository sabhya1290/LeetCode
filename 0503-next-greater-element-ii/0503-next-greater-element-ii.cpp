class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int l = arr.size();
        pair<int, short> maxi;
        maxi.first = arr[0];
        maxi.second = 0;
        for (int i = 0; i < l; i++)
        {
            if (arr[i] >= maxi.first)
            {
                maxi.first = arr[i];
                maxi.second = i;
            }
        }
        vector<int> res;
        stack<int> st;
        for (int j = maxi.second; j >= 0; j--)
        {
            while (!st.empty() && st.top() <= arr[j])
                st.pop();
            if (st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            st.push(arr[j]);
        }
        for (int j = (l - 1); j > maxi.second; j--)
        {
            while (!st.empty() && st.top() <= arr[j])
                st.pop();
            if (st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            st.push(arr[j]);
        }
        reverse(res.begin(), res.begin() + maxi.second + 1);
        reverse(res.begin() + maxi.second + 1, res.end());
        return res;
    }
};