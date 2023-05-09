class Solution {
public:
    int n;
    int m;
    vector<vector<int>> a;
    int new_color;
    int starting_pixel_color;

    void dfs(int row, int col) {
        if (a[row][col] == starting_pixel_color) {
            a[row][col] = new_color;

            if (row > 0) {
                dfs(row - 1, col);
            }
            if (col > 0) {
                dfs(row, col - 1);
            }
            if (row < n - 1) {
                dfs(row + 1, col);
            }
            if (col < m - 1) {
                dfs(row, col + 1);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        
        n = image.size();
        m = image[0].size();
        a = image;
        new_color = color;
        starting_pixel_color = image[sr][sc];

        dfs(sr, sc);    

        return a;
    }
};