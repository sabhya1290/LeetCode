class Solution {
    vector<int> nse(vector<int> & arr , int n ){
        vector<int> v(n , n);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;

    }
    vector<int> pse(vector<int> & arr , int n ){
        vector<int> v(n , -1);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i] ){
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;

    }
    vector<int> nge(vector<int> & arr , int n ){
        vector<int> v(n , n);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i] ){
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;

    }
    vector<int> pge(vector<int> & arr , int n ){
        vector<int> v(n , -1);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] < arr[i] ){
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;

    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse1 = pse(nums , n);
        vector<int> nse1 = nse(nums , n);
        vector<int> nge1 = nge(nums , n);
        vector<int> pge1 = pge(nums , n);
        long long  total = 0 ;

        for(int i = 0 ; i < n ;i++){
            int x = nse1[i] - i ; 
            int y = i - pse1[i];
            int z = nge1[i] - i ;
            int w = i - pge1[i];

            total += ((w * z*1LL) - (x * y*1LL))*nums[i];
        }
        return total;
    }
};