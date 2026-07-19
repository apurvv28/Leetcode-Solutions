class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for(int i : nums){
            sum = max(i, i+sum);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};