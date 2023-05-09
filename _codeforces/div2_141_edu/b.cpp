#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a;

    int m = n * n;
    int cur = 1;
    while (m >= cur) {
        if (m == cur) {
            a.push_back(cur);
        }
        else {
            a.push_back(m);
            a.push_back(cur);   
        }
        m--;
        cur++;
    }       

    cur = 0;

    int b[n][n];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            for (int j = n - 1; j >= 0; j--) {
                b[i][j] = a[cur];
                cur++;
            }
        }
        else {
            for (int j = 0; j <= n - 1; j++) {
                b[i][j] = a[cur];
                cur++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}