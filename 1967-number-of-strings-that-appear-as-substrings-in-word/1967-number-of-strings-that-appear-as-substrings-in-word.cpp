class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        string_view s(word);
        int count = 0;
        for(string_view p: patterns){
            count+=s.find(p)!=-1;
        }
        return count;
    }
};