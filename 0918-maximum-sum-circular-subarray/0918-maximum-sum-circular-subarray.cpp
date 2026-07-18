class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN;
        int currMax = 0;
        int minSum = INT_MAX;
        int currMin = 0;
        for(int i : nums){
            currMax = max(i, currMax + i);
            maxSum = max(maxSum, currMax);
            currMin = min(i, currMin + i);
            minSum = min(minSum, currMin);
            totalSum += i;
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum, totalSum - minSum);
    }
};