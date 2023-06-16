#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    if (n % 2 == 1) {
        n++;
    }

    cout << max((ll)(n * 2.5), (ll)15) << "\n";

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