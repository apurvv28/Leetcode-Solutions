class Solution {
public:
    string decodeString(string s){
        int index = 0;
        return solve(s, index);
    }
    string solve(string &s, int &i){
        string result = "";
        int number = 0;
        while(i < s.size() && s[i] != ']'){
            if(isdigit(s[i])){
                number = 0;
                while(i < s.size() && isdigit(s[i])){
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                i++;  // skip '['
                string inside = solve(s, i);
                i++;  // skip ']'
                while(number--){
                    result += inside;
                }
            }else{
                result += s[i];
                i++;
            }
        }
        return result;
    }
};