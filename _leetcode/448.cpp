class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n = a.size();

        for (int &x: a) {
            a[abs(x) - 1] = -1 * abs(a[abs(x) - 1]);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) 
                res.push_back(i + 1);
        }

        return res;
    }

    vector<int> findDisappearedNumbers2(vector<int>& a) {
        int n = (int)a.size();
        vector<int> used(n + 1, 0);
        for (int i = 0; i < n; i++) 
            used[a[i]] = 1;
        a.clear();
        for (int i = 1; i <= n; i++) {
            if (used[i] == 0) {
                a.push_back(i);
            }
        } 
        return a;
    }
};