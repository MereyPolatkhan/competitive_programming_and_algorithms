class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0; 

        int i = 0;
        int j = 0;

        while (i < (int)g.size() and j < (int)s.size()) {
            if (s[j] >= g[i]) {
                res++;
                j++;
                i++;
            }
            else {
                j++;
            }
        }

        return res;
    }
};