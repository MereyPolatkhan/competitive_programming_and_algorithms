class Solution {
public:
    bool check(string s, string t) {
        unordered_map<char, char> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.count(t[i]) == 0) {
                mp[t[i]] = s[i];
            }
            else {
                if (mp[t[i]] == s[i]) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return check(s, t) and check(t, s);
    }
};