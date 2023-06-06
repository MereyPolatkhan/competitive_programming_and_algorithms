#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[n - 1] > a[n]) {
        cout << -1 << "\n";
        return;
    }
    if (a[n] >= 0) {
        cout << n - 2 << "\n";
        for (int i = 1; i <= n - 2; i++) {
            cout << i << " " << n - 1 << " " << n << "\n";
        }
        return;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main() {
    
    // freopen("input.txt", "r", stdin);

    long long t;
    cin >> t;

    while (t--)
        solve();


    return 0;
}