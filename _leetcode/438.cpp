class Solution {
public:
    int ctoi(char &c) {
        return (int)c - (int)'a';
    }

    bool check(vector<int> &a, vector<int> &b) {
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) 
            return res;
        
        vector<int> a(26, 0);        
        vector<int> b(26, 0);
        

        for (int i = 0; i < p.size(); i++) {
            a[ctoi(s[i])]++;
            b[ctoi(p[i])]++;
        }
        
        if (check(a, b)) {
            res.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            a[ctoi(s[i - p.size()])]--;
            a[ctoi(s[i])]++;
            if (check(a, b)) {
                res.push_back(i - p.size() + 1);
            }
        }
        return res;

    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        if (s.size() < p.size()) return res;
        
        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i = 0; i < p.size(); i++) {
            a[p[i] - 'a']++;
            b[s[i] - 'a']++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] == b[i]) cnt++;
        }


        for (int i = 0; i < s.size() - p.size(); i++) {
            if (cnt == 26) {
                res.push_back(i);
            }
            int l = s[i] - 'a';
            int r = s[i + p.size()] - 'a';

            b[r]++;
            if (a[r] == b[r]) cnt++;
            else if (a[r] + 1 == b[r]) cnt--;

            b[l]--;
            if (a[l] == b[l]) cnt++;
            else if (a[l] - 1 == b[l]) cnt--;
            
        }   
        if (cnt == 26) {
            res.push_back(s.size() - p.size());
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        if (s.size() < p.size()) return res;
        
        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i = 0; i < p.size(); i++) {
            a[p[i] - 'a']++;
            b[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size() - p.size(); i++) {
            if (check(a, b)) {
                res.push_back(i);
            }
            int l = s[i] - 'a';
            int r = s[i + p.size()] - 'a';

            b[l]--;
            b[r]++;
            
        }   
        if (check(a, b)) {
            res.push_back(s.size() - p.size());
        }
        return res;
    }

    bool check(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};