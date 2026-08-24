class Solution {
public:
    vector<string> ans;
    void solve(string& temp, string& s, int i){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[i])){
            temp.push_back(s[i]);
            solve(temp, s, i+1);
            temp.pop_back();
        }else{
            temp.push_back(tolower(s[i]));
            solve(temp, s, i+1);
            temp.pop_back();

            temp.push_back(toupper(s[i]));
            solve(temp, s, i+1);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        string temp = "";
        solve(temp, s, 0);
        return ans;
    }
};