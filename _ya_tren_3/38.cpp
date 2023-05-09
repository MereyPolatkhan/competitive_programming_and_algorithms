#include <bits/stdc++.h>

using namespace std;


int a[1000][1000];



int main() {    
    int n, m, s, t, q;
    cin >> n >> m >> s >> t >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    a[s][t] = 2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}