#include <bits/stdc++.h>

using namespace std;

#define N 1000000

int a[N];
int dp[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = 0;
    dp[2] = abs(a[1] - a[2]);

    for (int i = 3; i <= n; i++) {
        int from_2 = abs(a[i - 2] - a[i]) + dp[i - 2];
        int from_1 = abs(a[i - 1] - a[i]) + dp[i - 1];
        dp[i] = min(from_1, from_2);
    }

    cout << dp[n];

    return 0;
}