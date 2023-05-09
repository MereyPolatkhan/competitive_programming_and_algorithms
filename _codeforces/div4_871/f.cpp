#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    vector<int> a(10000, 0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y]++;
    }

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }

    int x = 0, x_cnt = 0;
    int y = 0, y_cnt = 0;

    for (auto i : mp) {
        if (i.first != 1) {
            if (mp.size() == 2) {
                x = i.first;
                y = i.first;
            }
            else {
                if (i.second == 1) {
                    x = i.first;
                }
                else {
                    y = i.first;
                }
            }
        }
    }
    // cout << "-- ";
    cout << x << " " << y - 1 << "\n";
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