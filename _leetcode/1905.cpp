class Solution {
public:
    int n;
    int m;
    vector<vector<int>> a;
    vector<vector<int>> check;

    int res = 0;
    bool flag;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 0) {
            return;
        }
        if (check[i][j] == 0) {
            flag = false;
        }
        
        a[i][j] = 0;
        
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        a = grid2;
        check = grid1;
        
        n = grid1.size();
        m = grid1[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    flag = true; 
                    dfs(i, j);
                    if (flag) {
                        res++;
                    }
                }
            }
        } 

        return res;   
    }
};