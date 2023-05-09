#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];

int main() {
    int n, m;
    cin >> n >> m;

    if (n * (n - 1) / 2 != m) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] += 1;
        a[y][x] += 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";


    return 0;
}