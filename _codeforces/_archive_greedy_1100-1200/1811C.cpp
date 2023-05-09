#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    int m = n - 1;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];

    vector<int> a(n + 1);

    a[1] = b[1];
    for (int i = 2; i <= n - 1; i++) {
        a[i] = min(b[i], b[i - 1]);
    }
    a[n] = b[m];


    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

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