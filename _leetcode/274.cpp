class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        vector<int> cnt(n + 1, 0);
        for (int &x: a) {
            cnt[min(x, n)]++;
        }

        int k = 0;
        for (int i = n; i >= 0; i--) {
            k += cnt[i];
            if (k >= i) {
                return i;
            }
        }
        return 0;;
    }

    int hIndex2(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < a.size(); i++) {
            if (i + 1 <= a[i]) {
                continue;
            }
            else {
                return i;
            }
        }
        return a.size();
    }
};