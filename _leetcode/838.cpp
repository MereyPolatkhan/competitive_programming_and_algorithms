class Solution {
public:
    void goRL(string &s, int i, int j) {
        while (i < j) {
            s[i] = 'R';
            i++;
            s[j] = 'L';
            j--;
        }
    }
    void goL(string &s, int i) {
        while (i >= 1 and s[i - 1] == '.') {
            s[i - 1] = 'L';
            i--;
        }
    }
    void goR(string &s, int i, int j) {
        while (i < j) {
            s[i] = 'R';
            i++;
        }
    }
    string pushDominoes(string &s) {  
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'L') {
                goL(s, i);
            }
            else if (s[i] == 'R') {
                int j = i + 1;
                while (j < s.size() and s[j] == '.') {
                    j++;
                }
                if (j == s.size() || s[j] == 'R') {
                    goR(s, i, j);
                    j--;
                }
                else {
                    goRL(s, i, j);
                }
                i = j;
            }
            i++;
        }
        return s;
    }
};