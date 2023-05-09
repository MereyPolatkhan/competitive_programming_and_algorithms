#include <bits/stdc++.h>


using namespace std;

#define mod 1000000007
#define ull unsigned long long
#define N 10000

ull dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n, k;
    cin >> n >> k;

    for (ull i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }


    for (ull i = 1; i <= n; i++) {
        for (ull j = 1; j <= k; j++) {
            ull val;
            if (j >= i) {
                val = (dp[i - 1][j]) - (dp[i - 1][j - i]);
            }
            else {
                val = dp[i - 1][j];
            }   
            val %= mod;
            dp[i][j] = ((dp[i][j - 1]) + (val));
        }
    }


    // for (ull i = 0; i <= n; i++) {
    //     for (ull j = 0; j <= k; j++)  {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (k >= 1) {
        cout << ((dp[n][k]) - (dp[n][k - 1]));
    }
    else {
        cout << 1;
    }
    return 0;
}