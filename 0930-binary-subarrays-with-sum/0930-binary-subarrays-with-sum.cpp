class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n = nums.size();
        int prefix  = 0;
        int ans = 0;
        for(int i = 0;i < n; i++){
            prefix += nums[i];
            int need = prefix - goal;
            ans += mp[need];
            mp[prefix]++;
        }
        return ans;
    }
};