class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        int n = nums.size();
        mp[0] = -1;
        int ans = INT_MAX;
        long long prefix = 0;
        long long totalsum = 0;
        int target = 0;
        for(int i = 0;i < n; i++){
            totalsum += nums[i];
        }
        target = totalsum % p;
        if(target==0)
            return 0;
        for(int i = 0;i < n;i++){
            prefix += nums[i];
            int currRem = ((prefix % p) + p) % p;
            int need = (currRem - target + p) % p;
            if(mp.count(need)){
                ans = min(ans,i-mp[need]);
            }
            mp[currRem] = i;
        }
        return (ans == INT_MAX || ans == n) ? -1 : ans;
    }
};