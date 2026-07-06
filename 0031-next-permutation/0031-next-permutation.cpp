class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola = -1;
        for(int i = n-1; i>0;i--){
            if(nums[i]>nums[i-1]){
                gola = i-1;
                break;
            }
        }
        if(gola!=-1){
            int swap_i = gola;
            for(int i = n-1; i>=gola+1;i--){
                if(nums[i]>nums[gola]){
                    swap_i = i;
                    break;
                }
            }
            swap(nums[gola],nums[swap_i]);
        }
        reverse(nums.begin()+gola+1,nums.end());
    }    
};