class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cnt = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};