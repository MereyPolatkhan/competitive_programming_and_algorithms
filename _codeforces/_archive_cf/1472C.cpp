#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) dp[i] = a[i];

    for (int i = n; i >= 1; i--) {
        if (a[i] + i <= n) {
            dp[i] += dp[a[i] + i];
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}