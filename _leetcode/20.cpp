class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.size() == 0) return false;
                char top = st.top();
                char curr = s[i];
                if (top == '(' && curr == ')') st.pop();
                else if (top == '[' && curr == ']') st.pop();
                else if (top == '{' && curr == '}') st.pop();
                else return false;
            }
        }
        return st.size() == 0;
    }
};