// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.4 MB, less than 69.65% of C++ online submissions for Is Subsequence.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                i++;
            }
        }

        return (i == s.size());
    }
};