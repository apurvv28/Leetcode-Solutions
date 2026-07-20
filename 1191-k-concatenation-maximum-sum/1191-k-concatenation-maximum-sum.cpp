class Solution {
public:
    const int MOD = 1e9 + 7;
    long long kadane(vector<int>& nums) {
        long long curr = 0;
        long long best = 0;
        for(int x : nums){
            curr = max(0LL, curr + x);
            best = max(best, curr);
        }
        return best;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k){
        if (k == 1)
            return kadane(arr) % MOD;

        vector<int> twice = arr;
        twice.insert(twice.end(), arr.begin(), arr.end());
        long long bestTwo = kadane(twice);
        long long totalSum = 0;
        for (int x : arr)
            totalSum += x;

        if (totalSum > 0) {
            bestTwo += (long long)(k - 2) * totalSum;
        }
        return bestTwo % MOD;
    }
};