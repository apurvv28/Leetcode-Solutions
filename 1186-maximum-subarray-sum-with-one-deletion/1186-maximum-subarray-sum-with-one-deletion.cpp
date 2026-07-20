class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int keep = arr[0];
        int deleted = -999;
        int ans = arr[0];

        for(int i = 1; i < n; i++){
            int a = keep;
            int b = deleted;
            keep = max(arr[i],a+arr[i]);
            deleted = max(a,b+arr[i]);
            ans = max({ans,keep,deleted});
        }
        return ans;
    }
};