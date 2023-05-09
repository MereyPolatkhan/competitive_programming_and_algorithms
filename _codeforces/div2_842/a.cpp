#include <bits/stdc++.h>

using namespace std;

long long fac(long long n) {
    if (n == 0 || n == 1) return 1;
    long long j = 1;
    for (long long i = 2; i <= n; i++) {
        j = j * i;
    }
    return j;
}

void solve() {
    long long k;
    cin >> k;

    cout << k - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}