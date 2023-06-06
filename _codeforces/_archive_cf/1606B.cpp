#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

void solve() {

    ll n, k;
    cin >> n >> k;

    ll cnt = 0;
    ll comp = 1;
    while (comp < k) {
        comp *= 2;
        cnt++;
    }
    if (n <= comp) {
        cout << cnt << "\n";
        return;
    }
    cnt += (n - comp) / k;
    if ((n - comp) % k != 0) {
        cnt++;
    }
    cout << cnt << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}