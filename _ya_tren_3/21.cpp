#include <bits/stdc++.h>

using namespace std;


vector<int> dp(10007, 0);

int main() {

    int n;
    cin >> n;

    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n];

    return 0;
}