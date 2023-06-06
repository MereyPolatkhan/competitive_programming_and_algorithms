class Solution {
public:
    void func(vector<int> &a, string &s, char &c, int index) {
        a[index] = 0;
        int i = index - 1;
        int j = index + 1;
        
        while (0 <= i and s[i] != c) {
            a[i] = min(a[i], a[i + 1] + 1); i--;
        }
        
        while (j < a.size() and s[j] != c) {
            a[j] = min(a[j], a[j - 1] + 1); j++;
        }

    }

    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> a(n, 1e9);

        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                func(a, s, c, i);
            }
        }


        return a;
    }

};