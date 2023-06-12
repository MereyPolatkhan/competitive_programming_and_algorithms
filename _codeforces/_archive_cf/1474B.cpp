#include <bits/stdc++.h>

using namespace std;

bool check(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    long long d;
    cin >> d;

    long long p, q;
    p = d + 1;
    while (check(p) == false) p++;    
    q = p + d;
    while (check(q) == false) q++;

    cout << min(p * q, p * p * p) << "\n";
    
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}