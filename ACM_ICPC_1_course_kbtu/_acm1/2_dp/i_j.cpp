#include <bits/stdc++.h>

using namespace std;

long long dp[1000];

int main() {

    // abc 
    // no ab

    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= n; i++) {
        dp[i] = 3 * dp[i - 1] - dp[i - 2];
    }

    cout << dp[n];


    return 0;
}