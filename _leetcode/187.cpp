class Solution {
public:
    const int p = 5;

    int my_hash(string s) {
        int h = 0;
        for (int i = 0; i < s.length(); i++) {
            h = h * p + s[i];
        }
        return h;
    }


    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        int m = 10;

        if (s.size() < m) {
            return res;
        }
        

        
        int pm = 1; // p^{m-1}
        for (int i = 0; i < m-1; i++)
            pm = pm * p;

        unordered_map<int, int> mp;
    
        int hs = my_hash(s.substr(0, m));

        for (int i = 0; i + m <= n; i++) {
            if (mp[hs] == 1) {
                res.push_back(s.substr(i, m));
            }
            mp[hs]++;
            if (i + m < n)
                hs = (hs - pm * s[i]) * p + s[i + m];
        }

        return res;        
    }
};

class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) {
            return res;
        }

        unordered_map<string, int> mp;

        for (int i = 0; i < s.size() - 10 + 1; i++) {
            mp[s.substr(i, 10)]++;
        }

        for (auto &x: mp) {
            if (x.second >= 2) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};