class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int &x: nums) {
            mp[x]++;
        }

        vector< pair<int, int> > a;
        for (auto &i: mp) {
            a.push_back({i.second, i.first});
        }

        sort(a.rbegin(), a.rend());

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(a[i].second);
        }
        return res;
    }
};