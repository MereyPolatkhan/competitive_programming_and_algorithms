class Solution {
public:
    const int p = 3;

    long long my_hash(string s) {
        long long h = 0;
        for (int i = 0; i < s.length(); i++) {
            h = h * p + s[i];
        }
        return h;
    }

    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        unsigned long long pm = 1; // p^{m-1}
        for (int i = 0; i < k - 1; i++)
            pm = pm * p;

        unsigned long long hs = my_hash(s.substr(0, k));
        unordered_set<unsigned long long> st;

        for (int i = 0; i + k <= s.size(); i++) {
            st.insert(hs);            
            if (i + k < s.size())
                hs = (hs - pm * s[i]) * p + s[i + k];
        }

        
        return st.size() == 1 << k;
    }
};



class Solution2 {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        unordered_set<string> st;
        for (int i = 0; i < s.size() - k + 1; i++) {
            st.insert(s.substr(i, k));
        }

        return st.size() == 1 << k;
    }
};