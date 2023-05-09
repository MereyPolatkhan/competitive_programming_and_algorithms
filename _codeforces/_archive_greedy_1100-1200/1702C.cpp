#include <bits/stdc++.h>

using namespace std;

int n, k;
void solve() {

    cin >> n >> k;

    map<int, pair<int, int> > mp;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp.count(x)) {
            mp[x].second = i;
        }
        else {
            mp[x].first = i;
            mp[x].second = i;
        }
    }

    for (int i = 0; i < k; i++) {
        int from, to;
        cin >> from >> to;

        if (mp.count(from) == 0 || mp.count(to) == 0) {
            cout << "NO\n";
        }
        else if (mp[from].first < mp[to].second) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}