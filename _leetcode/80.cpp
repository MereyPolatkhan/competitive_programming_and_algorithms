class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (i < n + 1 and a[i] == a[i + 1]) {
                i++;
                cnt++;
            }
            cnt = min(cnt, 2);
            for (int k = 0; k < cnt; k++) {
                a[j] = a[i];
                j++;
            }
        }
        return j;
    }
};