#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long even = 0;
    long long odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even += a[i];
        }
        else {
            odd += a[i];
        }
    }
    if (even > odd) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }





    return 0;
}