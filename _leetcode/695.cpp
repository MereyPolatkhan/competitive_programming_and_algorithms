class Solution {
public:
    int res = 0;
    int temp = 0;
    int n;
    int m;
    vector<vector<int>> a;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 0){
            return;
        }
        a[i][j] = 0; 
        temp++;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        a = grid;        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    dfs(i, j);
                    res = max(res, temp);
                    temp = 0;
                }
            }
        }
        
        return res;
    }
};