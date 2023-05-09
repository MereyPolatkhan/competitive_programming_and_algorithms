#include <bits/stdc++.h>

using namespace std;

#define N 10000

int dp[N][N];


int main() {    
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];


    int m;
    cin >> m;
    vector<int> b(m + 1, 0);
    for (int j = 1; j <= m; j++) cin >> b[j];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }
    // cout << "\n\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    cout << dp[n][m] << "\n";
    


    return 0;
}