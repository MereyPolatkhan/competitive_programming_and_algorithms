#include <bits/stdc++.h>

using namespace std;

int a[1010][1010];
int used[1010][1010];
int n, m;

void dfs(int & sum, int i, int j) {
    if (a[i][j] == 0 || used[i][j] == 1) {
        return;
    }
    sum += a[i][j];
    used[i][j] = 1;
    dfs(sum, i + 1, j);
    dfs(sum, i - 1, j);
    dfs(sum, i, j + 1);
    dfs(sum, i, j - 1);
    
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }   
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (used[i][j] == 0) {
                int sum = 0;
                dfs(sum, i, j);
                res = max(res, sum);
                // cout << " --- " << sum << "\n";
            }   
        }
    }
    cout << res << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            used[i][j] = 0;
            a[i][j] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){ 
        solve();
    }



    return 0;
}