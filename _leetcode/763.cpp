class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int size = 0;
        int end = 0;
        
        int i = 0;
        while (i < s.size()) {

            size++;

            end = max(end, mp[s[i]]);

            if (end == i) {
                res.push_back(size);
                size = 0;
            }

            i++;
        }

        return res;
    }
};