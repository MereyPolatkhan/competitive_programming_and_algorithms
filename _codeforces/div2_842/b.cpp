#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int st = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == st) {
            st++;
        }
        else {
            cnt++;
        }
    }

    if (cnt % k != 0) {
        cout << cnt / k + 1 << "\n"; 
    }
    else {
        cout << cnt / k + 0 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}