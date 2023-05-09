#include <bits/stdc++.h>


using namespace std;

vector<int> dp(10000, 1e9);
vector<int> a(10000, 0);
vector<int> b(10000, 0);
vector<int> c(10000, 0);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }


    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        // a : 1
        for (int j = 0; j < 1; j++){
            dp[i + j] = min(dp[i + j], dp[i - 1] + a[i]);
        }
        
        // b : 2
        for (int j = 0; j < 2; j++) {
            dp[i + j] = min(dp[i + j], dp[i - 1] + b[i]);
        }

        // c : 3
        for (int j = 0; j < 3; j++) {
            dp[i + j] = min(dp[i + j], dp[i - 1] + c[i]);
        }

        // cout << "\n\n";
        // for (int i = 1; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }

    }
    cout << dp[n];
    return 0;
}