#include <iostream>

using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    // x --> 1x1
    // y --> 1x2
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                dp[i][j] = x;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    bool ok = (2 * x <= y);
    int sum = 0;
    if (ok == true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        cout << sum << "\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m-1; j++) {
                if (a[i][j] == '.' && a[i][j+1] == '.'){
                    dp[i][j] = 0;
                    dp[i][j+1] = y;
                    a[i][j] = '#';
                    a[i][j+1] = '#';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        cout << sum << "\n";
    }
}


int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--){
        solve();
    }


    return 0;
}