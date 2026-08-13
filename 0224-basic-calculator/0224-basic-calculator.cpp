class Solution {
public:
    int calculate(string s) {
        stack<long long> values;
        stack<char> operators;
        bool expectNumber = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (isdigit(s[i])) {
                long long num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                values.push(num);
                i--;
                expectNumber = false;
            }
            else if (s[i] == '(') {
                operators.push('(');
                expectNumber = true;
            }
            else if (s[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    performOperation(values, operators);
                }
                operators.pop();
                expectNumber = false;
            }
            else {
                char op = s[i];
                if (expectNumber) {
                    if (op == '+') {
                        continue;
                    }
                    if (op == '-') {
                        values.push(0);
                        operators.push('-');
                    }
                }
                else {
                    while (!operators.empty() && operators.top() != '(') {
                        performOperation(values, operators);
                    }
                    operators.push(op);
                }
                expectNumber = true;
            }
        }
        while (!operators.empty()) {
            performOperation(values, operators);
        }
        return (int)values.top();
    }
private:
    void performOperation(stack<long long>& values, stack<char>& operators) {
        long long b = values.top();
        values.pop();
        long long a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') {
            values.push(a + b);
        }
        else if (op == '-') {
            values.push(a - b);
        }
    }
};