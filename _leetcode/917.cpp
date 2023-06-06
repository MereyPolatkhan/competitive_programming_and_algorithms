class Solution {
public:
    bool check(char c) {
        return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z');
    }
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (check(s[i]) and check(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else {
                if (check(s[i]) == false) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return s;
    }
};