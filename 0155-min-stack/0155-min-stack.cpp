#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            // Encode the value
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < mini) {
            // Encoded value, restore previous minimum
            mini = 2LL * mini - st.top();
        }

        st.pop();
    }

    int top() {
        if (st.top() >= mini)
            return st.top();

        // Encoded value means current minimum is the actual top
        return mini;
    }

    int getMin() {
        return mini;
    }
};