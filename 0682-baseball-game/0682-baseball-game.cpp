class Solution {
public:
    int calPoints(vector<string>& operations) {
        int a, b;
        int ans = 0;
        stack<int> st;
        for(string i : operations){
            if(i == "C"){
                st.pop();
            }else if(i == "D"){
                st.push(st.top()*2);
            }else if(i == "+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.push(a);
                st.push(a+b);
            }else{
                st.push(stoi(i));
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};