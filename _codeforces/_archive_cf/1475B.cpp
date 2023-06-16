#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    ll y = n % 2020;

    ll xy = (n - y) / 2020;

    if (xy >= y) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}




int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}