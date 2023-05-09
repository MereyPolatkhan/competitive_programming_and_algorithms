#include <bits/stdc++.h>

using namespace std;

vector<int> dp(1000009, 1e9);
vector<int> arrived(1000009, 1e9);

int main() {

    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    
    
    dp[1] = 0;
    arrived[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i - 1 >= 1) {
            // dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (dp[i] > dp[i - 1] + 1) {
                dp[i] = dp[i - 1] + 1;
                arrived[i] = i - 1;
            }
        }
        if (i % 2 == 0) {
            // dp[i] = min(dp[i / 2] + 1, dp[i]);
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                arrived[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            // dp[i] = min(dp[i / 3] + 1, dp[i]);
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                arrived[i] = i / 3;
            }
        }
    }


    // cout << "i dp arr \n";
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " " << dp[i] << " " << arrived[i] << "\n";
    // }


    cout << dp[n] << "\n";

    vector<int> res;
    int i = n;
    while (i >= 1) {
        res.push_back(i);
        i = arrived[i];
    }
    reverse(res.begin(), res.end());
    for (int i : res) cout << i << " ";


    return 0;
}