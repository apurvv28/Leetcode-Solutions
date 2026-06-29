class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string result = "";
        int i = 0;
        int j = 0;
        while(i<n || j<m){
            if(i>n-1){
                result+=word2[j];
                j++;
            }else if(j>m-1){
                result+=word1[i];
                i++;
            }else{
                result+=word1[i];
                result+=word2[j];
                i++;
                j++;
            }
        }
        return result;

    }
};