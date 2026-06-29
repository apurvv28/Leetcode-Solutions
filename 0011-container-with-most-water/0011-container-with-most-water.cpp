class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxW = 0;
        int left = 0;
        int right = n-1;
        while(left<=right){
            int width = right - left;
            int h = min(height[left],height[right]);
            int water = width * h;
            maxW = max(water,maxW);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxW;
    }
};