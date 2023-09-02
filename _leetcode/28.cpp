class Solution {
public:
    vector<int> p_f(string s) { // O(n)
        int n = s.size();
        vector<int> p(n);
        p[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i - 1];
            while (j > 0 && s[j] != s[i])
                j = p[j - 1];
            if (s[i] == s[j]) 
                j = j + 1;
            p[i] = j;
        }
        return p;
    }

    int strStr(string s, string t) {
        if (s.size() < t.size()) 
            return -1;
        
        vector<int> a = p_f(t + '%' + s);

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == t.size()) {
                return i - 2 * t.size();
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int strStr(string s, string t) {
        if (s.size() < t.size()) 
            return -1;
        for (int i = 0; i < s.size() - t.size() + 1; i++) {
            if (s[i] == t[0]) {
                if (s.substr(i, t.size()) == t) {
                    return i;
                }
            }
        }

        return -1;
    }
};

class Solution3 {
public:
    int ctoi(char c) {
        return (int)c - (int)'a';
    }

    bool check_cnt(vector<int> & a, vector<int> & b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }


    int strStr(string s, string t) {
        if (s.size() < t.size()) {
            return -1;
        }
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        for (int i = 0; i < t.size(); i++) {
            b[ctoi(t[i])]++;
            a[ctoi(s[i])]++;
        }

        if (check_cnt(a, b) and (s.substr(0, t.size()) == t)) {
            return 0;
        }

        for (int i = t.size(); i < s.size(); i++) {
            a[ctoi(s[i])]++;
            a[ctoi(s[i - t.size()])]--;
            if (check_cnt(a, b) and (s.substr(i - t.size() + 1, t.size()) == t)) {
                return i - t.size() + 1;
            }
        }
        
        return -1;
    }
};