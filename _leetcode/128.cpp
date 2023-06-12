class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> st;
        for (int &x: a) {
            st.insert(x);
        }
        int res = 0;
        for (int x: a) {
            if (st.count(x - 1) == 0) {
                int cnt = 0;
                while (st.count(x)) {
                    x++;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    } 

    int longestConsecutive_nlogn(vector<int>& a) {
        if (a.size() == 0) {
            return 0;
        }
        sort(a.begin(), a.end());

        int res = 1;
        int cur = 1;

        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i + 1] - a[i] == 1) {
                cur++;
            }
            else if (a[i + 1] != a[i]){
                res = max(res, cur);
                cur = 1;
            }
        }

        return max(res, cur);
    }
};