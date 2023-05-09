class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector <string> ans;
        for (int i = 0; i < s.size(); i++) {
            mp[s.substr(i, 10)]++;
        }

        for (auto i: mp) {
            if (i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};