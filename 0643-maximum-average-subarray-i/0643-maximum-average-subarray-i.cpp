class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int window = 0;
        for(int i = 0;i<k;i++){
            window+=nums[i];
        }
        sum = window;
        for(int i = k;i<n;i++){
            window+=nums[i];
            window-=nums[i-k];
            sum=max(sum,window);
        }
        return (double)sum/k;
    }
};