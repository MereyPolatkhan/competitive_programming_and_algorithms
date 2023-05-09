#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    int c;
    cin >> c;
    c--;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[c][i] == 1) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}