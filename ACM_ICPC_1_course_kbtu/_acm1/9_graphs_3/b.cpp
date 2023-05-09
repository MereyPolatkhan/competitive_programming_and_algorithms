#include <bits/stdc++.h>

using namespace std;

int a[1007][1007];

int main() {
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = 1e9;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sum += a[i][j];
        }
    }
    cout << sum;

    return 0;
}