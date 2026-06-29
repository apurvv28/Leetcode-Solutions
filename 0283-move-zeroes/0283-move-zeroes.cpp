class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        int j = 0;
        while(j<n){
            if(nums[j]!=0){
                i++;
                swap(nums[j],nums[i]);
            }
            j++;
        }
    }
};