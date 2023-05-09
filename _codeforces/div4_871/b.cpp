#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt++;
        }
        else {
            res = max(res, cnt);
            cnt = 0;
        }
    }
            res = max(res, cnt);

    cout << res << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--){ 
        solve();
    }



    return 0;
}