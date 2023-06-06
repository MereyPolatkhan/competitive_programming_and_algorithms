#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;

    long long res = n / k;

    if (n % k >= 2) {
        res += 2;
    }
    else {
        res += 1;
    }


    cout << min(n, res) << "\n";

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