class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0];
        int minP = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int a = maxP;
            int b = minP;
            maxP = max({nums[i],a*nums[i],b*nums[i]});
            minP = min({nums[i],a*nums[i],b*nums[i]});
            ans = max(maxP, ans);
        }
        return ans;
    }
};