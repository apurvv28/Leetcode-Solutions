class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int result=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int need=sum-k;
            result+=mp[need];
            mp[sum]+=1;
        }
        return result;
    }
};