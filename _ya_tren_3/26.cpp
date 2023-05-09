#include <bits/stdc++.h>

using namespace std;

int dp[30][30];
int a[30][30];

int main() {


    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                a[i][j] = 1e9;
            }
            else {
                cin >> a[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) {
                continue;
            }
            else {
                a[i][j] = min(a[i - 1][j], a[i][j - 1]) + a[i][j];
            }
        }
    }


    cout << a[n][m];
    return 0;
}