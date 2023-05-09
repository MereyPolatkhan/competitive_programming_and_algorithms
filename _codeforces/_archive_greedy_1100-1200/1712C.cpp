#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = a[i];
    }

    int cnt = 0;
    for (int j = 0; j < 2; j++) { 
        for (int i = n - 2; i >= 0; i--) {
            if (mp[a[i]] > mp[a[i + 1]]) {
                mp[a[i]] = 0;
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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