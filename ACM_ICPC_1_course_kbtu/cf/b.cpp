#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i][j] >= 1 && a[i - 1][j] > 0) {
                a[i][j] += a[i - 1][j];
            }
            // if (a[i + 1][j] > a[i][j] + 1) {
            //     a[i + 1][j] = 0;
            // }
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++) {
            if (a[i][j] >= 1 && a[i][j - 1] > 0) {
                a[i][j] += a[i][j - 1];
            }
            // if (a[i][j + 1] > a[i][j] + 1) {
            //     a[i][j + 1] = 0;
            // }
        }
    }

    int mx = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            mx = max(mx, a[i][j]);
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    // cout << mx + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}