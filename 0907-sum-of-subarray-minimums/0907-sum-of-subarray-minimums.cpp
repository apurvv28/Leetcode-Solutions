#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        // Previous Less Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = i - st.top();
            } else {
                left[i] = i + 1;
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        // Next Less Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top() - i;
            } else {
                right[i] = n - i;
            }
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long prod = (1LL * left[i] * right[i]) % MOD;
            prod = (prod * arr[i]) % MOD;
            res = (res + prod) % MOD;
        }
        return res;
    }
};