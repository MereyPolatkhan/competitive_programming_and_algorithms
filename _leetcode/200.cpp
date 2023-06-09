class Solution {
public:
    int n;
    int m;
    vector<vector<char>> a;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '0') {
            return;
        }
        a[i][j] = '0';
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {    
        n = grid.size();
        m = grid[0].size();
        a = grid;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        return cnt;
    }
};