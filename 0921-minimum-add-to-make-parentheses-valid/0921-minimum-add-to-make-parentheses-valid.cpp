class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open = 0, close = 0;
        for(char ch : s){
            if(ch=='('){
                open++;
            }else{
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }
        return open + close;
    }
};