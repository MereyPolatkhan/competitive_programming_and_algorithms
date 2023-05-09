#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    }

    int r = n - 1;
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    }
    // cout << l + 1 << " " << r + 1<< "\n";

    while (1 <= l) {
        if (b[l - 1] <= b[l]) {
            l--;
        }
        else {
            break;
        }
    }

    while (r <= n - 2) {
        if (b[r] <= b[r + 1]) {
            r++;
        }
        else {
            break;
        }
    }

    cout << l + 1 << " " << r + 1 << "\n";
    
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