#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long res = 1;

    for (int i = 1; i <= n - 1; i++) {
        res *= 2;
    }

    cout << res << "\n";
}

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}