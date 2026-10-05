class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(char c : s){
            if(c=='('){
                st.push(ans);
                ans=0;
            }
            else{
                ans = st.top() + max(ans*2, 1);
                st.pop();
            }
        }
        return ans;
    }
};