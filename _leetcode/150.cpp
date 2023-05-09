class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        long long first, second;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (s == "+") {
                first = st.top(); st.pop();
                second = st.top(); st.pop();
                st.push(first + second);
            }
            else if (s == "-") {
                first = st.top(); st.pop();
                second = st.top(); st.pop();
                st.push(second - first);
            }
            else if (s == "/") {
                first = st.top(); st.pop();
                second = st.top(); st.pop();
                st.push(second / first);
            }
            else if (s == "*") {
                first = st.top(); st.pop();
                second = st.top(); st.pop();
                st.push(first * second);
            }
            else {
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};