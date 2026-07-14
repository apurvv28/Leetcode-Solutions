class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int n = nums.size();
        int prefix = 0;
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(nums[i]==0){
                prefix--;
            }else{
                prefix++;
            }
            if(mp.find(prefix)!=mp.end()){
                ans=max(ans,i-mp[prefix]);
            }else{
                mp[prefix]=i;
            }
        }
        return ans;
    }
};