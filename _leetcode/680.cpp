class Solution {
public:
    bool func(int i, int j, string s) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        bool used = false;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                if (used) {
                    return false;
                }
                else {
                    return func(i + 1, j, s) or func(i, j - 1, s);
                }
            }
        }      
        return true;
    }
};