#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, string> > a;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        string s;
        cin >> s;
        a.push_back({m, s});
    }

    int obe = 1e9;
    int fst = 1e9;
    int scd = 1e9;

    for (int i = 0; i < n; i++) {
        if (a[i].second == "11") {
            obe = min(obe, a[i].first);
        }

        if (a[i].second == "10") {
            fst = min(fst, a[i].first);
        }
        if (a[i].second == "01") {
            scd = min(scd, a[i].first);
        }
    }

    int res = min(obe, fst + scd);
    if (res == 1e9) {
        cout << -1 << "\n";
    }
    else cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){ 
        solve();
    }



    return 0;
}