#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pi;

long long func(long long a1, long long an, long long n) {
    return (a1 + an) * n / 2;
}
void solve() {
    long long n;
    cin >> n;

    if (n == 4) {
        cout << 26 << "\n";
        return;
    }
    long long sum_ar = func(10, 2 * n, n - 4);
    cout << 26 + (sum_ar) + n - 4 << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}