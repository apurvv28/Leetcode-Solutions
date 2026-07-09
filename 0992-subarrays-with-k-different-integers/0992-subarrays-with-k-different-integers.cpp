class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        int ib = 0;
        int result = 0;
        while(j<n){
            mp[nums[j]]++;

            //Handle invalid subarray
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
                ib = i;
            }

            //Handle to find the smallest valid subarray ending at j (by shrinking)
            while(mp[nums[i]]>1){
                mp[nums[i]]--;
                i++;
            }

            if(mp.size()==k){
                result += (1+i-ib);
            }
            j++;
        }
        return result;
    }
};