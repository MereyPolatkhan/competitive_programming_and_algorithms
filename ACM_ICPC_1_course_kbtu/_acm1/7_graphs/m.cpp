#include <bits/stdc++.h>

using namespace std;

int kk = 1;

char a[1000][1000];

void dfs(int i, int j, int & cnt, vector<vector<int>> & used, int n, int m) {
    if (i < 0 or j < 0 or i >= n or j >= m or used[i][j] == 1 or a[i][j] == '#') {
        return;
    }
    cnt++;
    used[i][j] = 1;
    dfs(i + 1, j, cnt, used, n, m);
    dfs(i - 1, j, cnt, used, n, m);
    dfs(i, j + 1, cnt, used, n, m);
    dfs(i, j - 1, cnt, used, n, m);

}

void solve() {
    int n, m;
    cin >> m >> n;

    int ii, jj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                ii = i;
                jj = j;
            }
        }
    }

    vector<vector<int>> used(1000, vector<int>(1000, 0));
    int cnt = 0;
    dfs(ii, jj, cnt, used, n, m);
    cout << "Case " << kk++ << ": " << cnt << "\n";
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}