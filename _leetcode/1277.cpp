#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1 && i != 0 && j != 0) {
                    int minimum = min({matrix[i - 1][j], 
                    matrix[i - 1][j - 1], 
                    matrix[i][j - 1]});

                    matrix[i][j] += minimum;
                }
                res += matrix[i][j];
            }   
        }
        cout << "matrix = \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }   
            cout << endl;
        }
        cout << "res = " << res << "\n";
    }
};

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solution s;


    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    s.countSquares(v);

    return 0;
}