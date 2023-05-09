#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int a, b, q;
    cin >> a >> b >> q;


    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll cnt = 0;
        for (int i = l; i <= r; i++) {
            if (i % a % b != i % b % a) {
                cout << "i = " << i << "  ";
                cnt++;
            }
        }
        cout << cnt << " ";
    }

    cout << "\n";
    cout << "\n";
    cout << "\n";


}


int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}