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
        a[x][y] = 1;
        a[y][x] = 1;
    }

    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cnt++;
            }
        }
        s.insert(cnt);
    }
    cout << s.size();


    return 0;
}