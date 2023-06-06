class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> a;
        int cnt = 0;
        char cur = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == cur) {
                cnt++;
            }
            else {
                a.push_back(cnt);
                cur = s[i];
                cnt = 1;
            }
        }
        a.push_back(cnt);
     
        
        int res = 0;
        for (int i = 0; i < a.size() - 1; i++) {
            res += min(a[i], a[i + 1]);
        }
        return res;
    }
};