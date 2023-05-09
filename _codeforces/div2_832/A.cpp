#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<long long> a, b;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x >= 0) a.push_back(x);
        else b.push_back(x);
    }

    long long sum1 = 0, sum2 = 0;
    for (auto i: a) sum1 += i;
    for (auto i: b) sum2 += i;

    cout << abs(abs(sum1) - abs(sum2)) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}