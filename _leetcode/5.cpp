class Solution {
public:
    int len = 0;
    string res = "";
  
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            func(s, i, i);
            func(s, i, i + 1);
        }
        return res;
    }

    void func(string s, int l, int r) {
        while (l >= 0 and r < s.size() and s[l] == s[r]) {
            int curlen = r - l + 1;
            if (curlen > len) {
                len = curlen;
                res = s.substr(l, len);
            }
            r++;
            l--;
        }
    }
};