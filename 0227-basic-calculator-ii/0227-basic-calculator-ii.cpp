class Solution {
public:

    int precedence(char ch) {
        if(ch == '+' || ch == '-') {
            return 1;
        }
        else if(ch == '*' || ch == '/') {
            return 2;
        }
        return 0;
    }

    int calculate(string s) {
        stack<char> st;
        vector<string> rpn;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ')
                continue;
            // Read complete number
            if(isdigit(s[i])){
                string num;
                while(i < s.length() && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                rpn.push_back(num);
                i--;
            }
            else {
                while(!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                    rpn.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            rpn.push_back(string(1, st.top()));
            st.pop();
        }

        stack<int> st1;
        for(string token : rpn) {
            if(isdigit(token[0])) {
                st1.push(stoi(token));
            }
            else {
                int b = st1.top();
                st1.pop();
                int a = st1.top();
                st1.pop();
                if(token == "+")
                    st1.push(a + b);
                else if(token == "-")
                    st1.push(a - b);
                else if(token == "*")
                    st1.push(a * b);
                else
                    st1.push(a / b);
            }
        }
        return st1.top();
    }
};