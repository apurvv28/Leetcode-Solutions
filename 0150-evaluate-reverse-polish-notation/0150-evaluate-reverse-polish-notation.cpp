class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string i : tokens){
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                st.push(stoi(i));
            }else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(i == "+"){
                    st.push(a+b);
                }else if(i == "-"){
                    st.push(a-b);
                }else if(i == "*"){
                    st.push(a*b);
                }else{
                    st.push(a/b);
                }
            }
        }
        return st.top();
    }
};