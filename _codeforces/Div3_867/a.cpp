#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

void solve() {
    int n, t;
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int res = -1e9;
    int interesting = -1e9;
    for (int i = 0; i < n; i++) {
        if (t >= a[i]) {
            if (interesting < b[i]) {
                res = i;
                interesting = b[i];
            }
        }
        t--;
    }
    if (res == -1e9){ 
        cout << -1 << "\n";
    }
    else {
        cout << res + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }




    return 0;
}