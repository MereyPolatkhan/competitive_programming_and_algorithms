#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

void solve() {
    int n;
    cin >> n;
    vector<ull> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != 1) {
            ull x = a[i] * a[i + 1];
            a[i + 1] = x;
            a[i] = 1;
        }
    }
    ull sum = 0;

    for (ull i: a) sum += i;
    cout << sum * 2022;
    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}