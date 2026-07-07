class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0;
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax<rmax){
                ans+=min(lmax,rmax)-height[l];
                l++;
            }else{
                ans+=min(lmax,rmax)-height[r];
                r--;
            }
        }
        return ans;
    }
};