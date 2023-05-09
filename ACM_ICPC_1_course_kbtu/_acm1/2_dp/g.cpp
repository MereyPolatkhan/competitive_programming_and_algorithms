#include <bits/stdc++.h>

using namespace std;

#define N 10009

int n, m;
int used[N];
int dp[N];
vector<int> g[N];

void dfs(int v) { // v - y
    used[v] = 1;
    for (int y : g[v]) {
        if (used[y] == 0) {
            dfs(y);
        }
        dp[v] = max(dp[v], dp[y] + 1);
    }
}


int main() {
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            dfs(i);
        }
    }

    int mx = -1e9;

    for (int i = 1; i <= n; i++) {
        // cout << i << " " << dp[i] << "\n"; 
        mx = max(mx, dp[i]);
    }

    cout << mx;

    return 0;
}