#include <bits/stdc++.h>

using namespace std;

vector<int> a(10000, 0);
vector<int> b(10000, 0);
int dp[10000][10000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m;
    cin >> m;
    
    for (int i = 1; i <= m; i++) cin >> b[i];



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
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
    //     } cout << "\n";
    // }
    
    // cout << "\n\n";

    int i = n;
    int j = m;
    vector<int> res;
    
    while (i >= 1 and j >= 1) {
        if (dp[i - 1][j] == dp[i][j]) {
            i--;
        }

        else if (dp[i][j - 1] == dp[i][j]) {
            j--;
        }    
        else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            res.push_back(a[i]);
            i--;
            j--;
        }
        
    }

    reverse(res.begin(), res.end());

    for (int i : res) cout << i << " ";


    return 0;
}