class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int depth = 0;
        int maxD = 0;
        for(char ch : s){
            if(ch=='('){
                depth++;
                maxD = max(depth, maxD);
            }else if(ch==')'){
                depth--;
            }
        }
        return maxD;
    }
};