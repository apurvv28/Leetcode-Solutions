class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = piles[0];
        int ans = 0;
        for(int pile : piles){
            right = max(right,pile);
        }
        while(left<=right){
            int mid = left + (right-left) / 2;
            long maxhrs = 0;
            for(int a : piles){
                maxhrs += (long)(a+mid-1)/mid;
            }
            if(maxhrs<=h){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};