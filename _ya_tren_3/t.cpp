#include <bits/stdc++.h>


using namespace std;

vector<int> dp(1000000, 0);

int main() {

    int n;
    cin >> n;
    dp[1] = 2;
    dp[2] = 4;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i] * 2 - 2;
    }

    cout << dp[n];
    

    return 0;
}