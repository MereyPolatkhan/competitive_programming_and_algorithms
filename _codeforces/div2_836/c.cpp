#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n, x;
    cin >> n >> x;
    long long a[n + 1];
    for (long long i = 2; i < n; i++) a[i] = INT_MAX;
    a[1] = x;
    a[n] = 1;
    unordered_set<long long> hs;
    hs.insert(x);
    hs.insert(1);
    for (long long i = 2; i < n; i++) {
        for (long long j = i; j <= n; j++) {
            if (j % i == 0 && hs.count(j) == 0) {
                hs.insert(j);
                a[i] = j;
                break;
            }
        }
    }
    for (long long i = 1; i <= n; i++) {
        if (a[i] == INT_MAX) {
            cout << -1 << "\n";
            return;
        }
    }
    for (long long i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    long long n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}