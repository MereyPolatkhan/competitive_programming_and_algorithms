#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000 + 7; 

#define ull unsigned long long

void solve() {
    ull n;
    cin >> n;

    ull a = ((n * (n + 1) % MOD) * ((4 * n - 1) % MOD)) % MOD;
    cout << ((a) * (2022 / 6)) % MOD << "\n";


}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}