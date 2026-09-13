class Solution {
public:
    void solve(vector<int> &input, int idx, vector<int> &temp, vector<vector<int>> &ans, int k){
        if(idx==input.size()){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        temp.push_back(input[idx]);
        solve(input, idx+1, temp, ans, k);
        temp.pop_back();
        solve(input, idx+1, temp, ans, k);
    }
    vector<vector<int>> combine(int n, int k){
        vector<int> input;
        for(int i = 1; i<=n; i++){
            input.push_back(i);
        }
        vector<int> temp;
        vector<vector<int>> ans;
        solve(input, 0, temp, ans, k);
        return ans;
    }
};