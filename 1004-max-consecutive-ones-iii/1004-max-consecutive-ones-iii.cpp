class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int window = 0;
        int i = 0;
        for(int j = 0;j<n;j++){
            window = window + nums[j];
            while(window+k < j-i+1){
                window = window - nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};