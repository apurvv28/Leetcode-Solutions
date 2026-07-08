class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0;
        int j = 0;
        long long ans = 0, sum = 0;
        while(j<n){
            while(st.count(nums[j])){
                sum -=nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            st.insert(nums[j]);
            if(j-i+1==k){
                ans = max(sum,ans);
                sum -=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};