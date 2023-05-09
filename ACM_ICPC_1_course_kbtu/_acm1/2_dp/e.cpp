#include <bits/stdc++.h>

using namespace std;

long long a[1000][1000];
long long dp[1000][1000];

int main() {
    // freopen("slalom.in", "r", stdin);
    // freopen("slalom.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            dp[i][j] = -1e9;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 and j == 1) {
                dp[i][j] = a[i][j];
            }
            else {
                dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }


    long long res = -1e5;

    for (int i = n; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    


    return 0;
}