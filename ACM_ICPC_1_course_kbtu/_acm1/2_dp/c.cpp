#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];


int main() {
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    int n, m;
    cin >> n >> m;


    a[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > 0) {
                a[i + 2][j + 1] += a[i][j];
                a[i + 1][j + 2] += a[i][j];
            }
        }
    }

    cout << a[n][m];
    

    return 0;
}