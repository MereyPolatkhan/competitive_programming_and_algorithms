class Solution {
public:
    string make_str(char a, char b, char c) {
        string s = "";
        s += a; s += b; s += c;
        return s;
    }

    int convert(char c) {
        return (int)c - (int)'a';
    }

    void func(unordered_set<string> & st, string & s, int first, int last) {
        for (int i = first + 1; i <= last - 1; i++) {
            st.insert(make_str(s[first], s[i], s[last]));
        }
    }

    int countPalindromicSubsequence(string s) {
        unordered_set<string> st;
        vector<bool> used(26, false);

        for (int i = 0; i < s.size(); i++) {
            if (used[convert(s[i])] == false) {
                for (int j = s.size() - 1; j > i + 1; j--) {
                    if (s[i] == s[j]) {
                        func(st, s, i, j);
                        break;
                    }
                }
                used[convert(s[i])] = true;
            }    
        }

        return st.size();
    }
};