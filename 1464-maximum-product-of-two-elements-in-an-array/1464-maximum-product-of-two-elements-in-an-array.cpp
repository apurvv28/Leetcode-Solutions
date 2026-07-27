class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 1;
        int b = 1;
        for(int i : nums){
            if(a <= i){
                b = a;
                a = i;
            }else if(b <= i){
                b = i;
            }
        }
        return (a - 1) * (b - 1);
    }
};