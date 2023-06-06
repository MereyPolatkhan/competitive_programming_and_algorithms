class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& qs) {
        long long res = 0;
        int row = n, col = n;

        vector<int> row_used(n, 0), col_used(n, 0);

        for (int i = qs.size() - 1; i >= 0; i--) {
            if (qs[i][0] == 0) {
                if (row_used[qs[i][1]] == 0) {
                    row_used[qs[i][1]] = 1;
                    res += col * qs[i][2];
                    row--;
                }
            }
            else {
                if (col_used[qs[i][1]] == 0) {
                    col_used[qs[i][1]] = 1;
                    res += row * qs[i][2];
                    col--;
                }
            }
        }
        return res;
    }

};