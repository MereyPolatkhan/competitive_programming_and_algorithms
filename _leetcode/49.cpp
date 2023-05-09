class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> a;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            um[s].push_back(strs[i]);
        }

        for (auto i: um) {
            a.push_back(i.second);
        }

        return a;
    }
};