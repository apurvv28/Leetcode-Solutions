class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        mp[0] = 1;
        int prefix = 0;
        int ans = 0;
        for(int i = 0;i < n;i++){
            prefix += nums[i];
            int rem = prefix % k;
            if(rem<0){
                rem += k;
            }
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};