// n^2
#include <bits/stdc++.h>

using namespace std;

#define mx_size 1000000

long long dp[mx_size];
long long a[mx_size];

int main() {
    long long n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    long long res = 0;

    for (long long i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    cout << res;

    return 0;
}