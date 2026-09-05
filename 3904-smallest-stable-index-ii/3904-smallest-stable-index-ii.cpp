class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxS = -1;
        int flag = 0, cMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxS = max(maxS, nums[i]);

            if (i == flag) cMax = maxS;

            if (nums[i] < cMax - k)
                flag = i + 1;
        }

        return flag < nums.size() ? flag : -1;
    }
};