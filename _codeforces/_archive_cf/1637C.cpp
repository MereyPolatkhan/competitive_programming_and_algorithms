#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 3 and a[1] % 2 == 1) {
        cout << -1 << "\n";
        return;
    }

    int mx = INT_MIN;
    for (int i = 1; i < n - 1; i++) {
        mx = max(mx, a[i]);
    }
    if (mx == 1) {
        cout << -1 << "\n";
        return;
    }
    

    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        if (i != 0 and i != n - 1) {
            cnt += (a[i] + 1) / 2;
        }
    }

   
    cout << cnt <<  "\n";


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