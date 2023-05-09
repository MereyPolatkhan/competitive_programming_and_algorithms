#include <bits/stdc++.h>

using namespace std;

void solve() {  

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n / 2; i++) {
            cout << 1 << " " << -1 << " ";
        }
        cout << "\n";
    }
    else {
        if (n == 3) cout << "NO\n";
        else {
            cout << "YES\n";
            int k = n / 2;
            cout << 1 - k << " ";
            for (int i = 0; i < (n - 1) / 2; i++) {
                cout << k << " " << 1 - k << " ";
            }
            cout << "\n";
        }
    }

}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }



    return 0;
}