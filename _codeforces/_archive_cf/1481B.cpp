#include <bits/stdc++.h>



using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                cout << -1 << "\n";
                return;
            }
            if (a[i] < a[i + 1]) {
                a[i]++;
                if (j == k) {
                    cout << i << "\n";
                    return;
                }
                break;
            }
        }
    }
    cout << -1 << "\n";
        

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