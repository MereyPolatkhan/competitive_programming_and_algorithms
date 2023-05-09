#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            cout << n - (i / 2) << " ";
        }
        else {
            cout << i / 2 << " ";
        }
    }
    cout << "\n";
}


int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}