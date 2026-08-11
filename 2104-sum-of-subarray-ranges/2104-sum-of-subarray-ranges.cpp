class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n);
        vector<long long> right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }
            st.push(i);
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n);
        vector<long long> right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }
            st.push(i);
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};