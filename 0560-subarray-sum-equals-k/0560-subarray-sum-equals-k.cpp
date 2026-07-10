class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int remove=sum-k;
            count+=mp[remove];
            mp[sum]+=1;
        }
        return count;
    }
};