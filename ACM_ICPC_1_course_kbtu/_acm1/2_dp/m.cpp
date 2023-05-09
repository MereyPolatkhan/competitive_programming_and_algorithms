#include <bits/stdc++.h>

using namespace std;

#define N 10000

int a[N][N];
int dp[N][N];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (i == 1 and j == 1) {
                dp[i][j] = a[i][j];
            }
            else {
                dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }

        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " " ;
        }
        cout << "\n";
    }



    return 0;
}