#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    sort(b, b + n);

    int mx = b[n - 1];
    int smax = b[n - 2];

    for (int i = 0; i < n; i++) {
        if (a[i] != mx) {
            cout << a[i] - mx << " ";
        }
        else {
            cout << mx - smax << " ";
        }
    }
    cout << "\n";
}


int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}