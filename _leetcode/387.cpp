class Solution {
public:
    int firstUniqChar(string s) {
        int res = s.size();
        unordered_map<char, pair<int, int> > mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].first = i;
            mp[s[i]].second += 1;
        } 

        for (auto i: mp) {
            if (i.second.second == 1) {
                res = min(res, i.second.first);
            }
        }

        return res == s.size() ? -1 : res;
    }
};