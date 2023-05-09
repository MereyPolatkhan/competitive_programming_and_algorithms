#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cnt1++;
        } 
    }

    cout << (cnt1 + 1) / 2 + (n - cnt1) << "\n";

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}