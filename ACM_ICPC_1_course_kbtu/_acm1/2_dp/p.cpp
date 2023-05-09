// n^2
#include <bits/stdc++.h>

using namespace std;

int dp[10001][10001];

// vector<int> dp(10001, 1e9);


int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b;
    set<int> bs;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bs.insert(a[i]);
    }


    for (int n : bs) {
        b.push_back(n);
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    cout << dp[n][n];

    return 0;
}