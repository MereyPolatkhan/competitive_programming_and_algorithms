#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = -1, r = -1;

    for (int i = 0; i <= n - 2; i++) {
        if (a[i] == a[i + 1]) {
            l = i;
            break;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            r = i;
            break;
        }
    }

    if (l == -1 or r == -1 or l == r) {
        cout << 0 << "\n";
        return;
    }

    cout << max(1, r - l - 1) << "\n";

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}