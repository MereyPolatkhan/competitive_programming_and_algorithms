#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];


    int res_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = a[i] + 1;
            res_cnt++;
        }
    } 


    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }


    if (sum == 0) {
        cout << res_cnt + 1 << "\n";
    }
    else cout << res_cnt << "\n";
}


int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}