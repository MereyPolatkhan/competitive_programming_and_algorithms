#include <bits/stdc++.h>

using namespace std;

int dp[300][300];
int a[300][300];
char arrived[300][300];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) {
                continue;
            }
            else {
                int come = max(a[i - 1][j], a[i][j - 1]);
                if (come == a[i - 1][j]) {
                    arrived[i][j] = 'D';
                }
                else {
                    arrived[i][j] = 'R';
                }
                a[i][j] += come;
            }
        }
    }


    cout << a[n][m] << "\n";

    vector<char> res;

    int i = n;
    int j = m;
    while (i >= 1 and j >= 1){
        res.push_back(arrived[i][j]);
        if (arrived[i][j] == 'D') {
            i--;
        }
        else {
            j--;
        }
    }
    // cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--) {
        if (res[i] == 'D' or res[i] == 'R') cout << res[i] << " ";
    }

    return 0;
}