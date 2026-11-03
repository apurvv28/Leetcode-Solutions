class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0;
        for(int i : nums){
            count+=mx-i;
        }
        return count;
    }
};