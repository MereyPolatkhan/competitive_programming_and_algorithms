#include <bits/stdc++.h>


using namespace std;


void solve() {
    int x, k;
    cin >> x >> k;

    if (x % k == 0) {
        cout << 2 << "\n" << x - 1 << " " << 1 << "\n";
    }
    else {
        cout << 1 << "\n" << x << "\n";
    }
}

int main() {
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