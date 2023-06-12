class Solution {
public:
    string func(string &s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '@') {
                while (i < s.size()) {
                    res += s[i];
                    i++;
                }
            }
            else if (s[i] == '.') {
                continue;
            }
            else if (s[i] == '+') {
                while (s[i + 1] != '@') {
                    i++;
                }
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (string &s: emails) {
            st.insert(func(s));
        }
        return st.size();
    }
};