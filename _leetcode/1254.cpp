class Solution {
public:
    int res = 0;

    int cur = 0;

    int n;
    int m;
    vector<vector<int>> a;

    void dfs(int i, int j) {
        if ((a[i][j] == 0) && (i < 1 || j < 1 || i > n - 2 || j > m - 2)) {
            cur = -1000000000;
            return;
        }
        if (a[i][j] == 1) {
            return;
        }
        cur++;
        a[i][j] = 1;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);

    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        a = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    dfs(i, j);
                    if (cur > 0) {
                        res++;
                    }
                    cur = 0;
                }
            }
        }

        return res;
    }
};