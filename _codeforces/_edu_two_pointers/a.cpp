#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1;
    long long res = 0;
    long long x = a[1];
    for (int r = 1; r <= n; r++) {
        x = __gcd(x, a[r]);
        while (good()) { // good() when GCD == 1
            // remove from GCD a[l]
            l++;
        }
        res = min(res, r - l + 1);
    }
    cout << res << "\n";
    
    
    return 0;
}