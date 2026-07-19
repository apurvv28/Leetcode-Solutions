class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int largeSum = 0;
        int result = 0;
        for(int i = 0;i<n;i++){
            largeSum += nums[i];
            maxSum = max(largeSum,maxSum);
            if(largeSum < 0){
                largeSum = 0;
            }
        }
        int minSum = INT_MAX;
        int smallSum = 0;
        for(int i = 0; i<n;i++){
            smallSum +=nums[i];
            minSum = min(smallSum, minSum);
            if(smallSum > 0){
                smallSum = 0;
            }
        }
        return max(maxSum, abs(minSum));
    }
};