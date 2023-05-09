#include <bits/stdc++.h>

using namespace std;

int a[100][100];

int main() {
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

    int n = 8;

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            a[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i == n and j == 1) {
                continue;
            }
            else {
                a[i][j] += min({a[i][j - 1], a[i + 1][j], a[i + 1][j - 1]});
            }
        }   
    }


    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << a[1][n];
    return 0;
}