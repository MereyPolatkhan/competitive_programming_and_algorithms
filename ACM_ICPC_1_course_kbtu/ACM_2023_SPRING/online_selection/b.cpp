#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long res = 0;

    for (int i = 0; i < n; i+=2) {
        res += (abs(a[i] - a[i+1]));
    }

    cout << res << "\n";






















}


int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }


    return 0;
}