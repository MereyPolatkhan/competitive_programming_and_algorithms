class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for (char &c: text) {
            mp[c]++;
        }

        unordered_map<char, int> balloon;
        string s = "balloon";
        for (char &c: s) {
            balloon[c]++;
        }


        int res = 1e9;
        
        for (auto &i: balloon) {
            res = min(res, (mp[i.first] / i.second));
        }


        return res;
    }
};