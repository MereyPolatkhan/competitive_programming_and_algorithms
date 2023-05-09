#include <bits/stdc++.h>

using namespace std;


vector<int> dp(1000, 1e9);

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a, a + n + 1);

    dp[1] = 0;
    dp[2] = abs(a[1] - a[2]);
    dp[3] = abs(a[2] - a[3]) + dp[2];
    for (int i = 4; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + abs(a[i] - a[i - 1]);
    }

    cout << dp[n];


    return 0;
}