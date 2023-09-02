class Solution {
public:
    void make_pref(vector<long long>& a) {
        for (int i = 1; i < a.size(); i++) {
            a[i] += a[i - 1];
        }
    }

    void make_suf(vector<long long>& a) {
        for (int i = a.size() - 2; i >= 0; i--) {
            a[i] += a[i + 1];
        }
    }

    void print(vector<vector<long long>> &a) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    long long gridGame(vector<vector<int>>& grid) {
        vector<vector<long long>> a(2);
        for (int i = 0; i < grid[0].size(); i++) {
            a[0].push_back(grid[0][i]);
        }      
        for (int i = 0; i < grid[1].size(); i++) {
            a[1].push_back(grid[1][i]);
        }      

        // print(a);

        make_pref(a[0]);
        make_suf(a[1]);

        // print(a);

        int i = 0;
        for (int j = 0; j < a[0].size(); j++) {
            if (a[0][j] + a[1][j] > a[0][i] + a[1][i]) {
                i = j;
            }
        }

        return i;
    }
};