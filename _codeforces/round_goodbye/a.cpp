#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int j = 0; j < m; j++) {
        int minn = a[0];
        for (int i = 0; i < n; i++) {
            minn = min(minn, a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == minn) {
                a[i] = b[j];
                break;
            }
        }
    }


    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    cout << res << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }



    return 0;
}