#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] += 1;
        a[y][x] += 1;
    }

    
    int c;
    cin >> c;
    int cnt = 0;
    c--;
    for (int i = 0; i < n; i++) {
        if (a[c][i] != 0) cnt++;
    }
    cout << cnt;
    return 0;0
}