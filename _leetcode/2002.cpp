class Solution {
public:
    int res = 1;

    bool is_palindrom(string &k) {
        for (int i = 0; i < (int)k.size() / 2; i++) {
            if (k[i] != k[(int)k.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void func(string &s, string &s1, string &s2, int i) {
        if (i >= s.size()) {
            if (is_palindrom(s1) and is_palindrom(s2)) {
                res = max(res, (int)s1.size() * (int)s2.size());
            }
            return;
        }
        s1.push_back(s[i]);
        func(s, s1, s2, i + 1);
        s1.pop_back();

        s2.push_back(s[i]);
        func(s, s1, s2, i + 1);
        s2.pop_back();

        func(s, s1, s2, i + 1);
    }

    int maxProduct(string s) {  
        string s1 = "", s2 = "";
        func(s, s1, s2, 0);

        return res;      
    }
};