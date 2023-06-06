#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, int n) {
    int r = (i - 1) + 1 + (n - j);
    // cout << "i j n r : " << i << " " << j << " " << n << " " << r << "\n";
    return r;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        mp[a[i]].push_back(i);
    }

    // for (auto i: mp){
    //     cout << i.first << "==";
    //     for (int j: i.second) {
    //         cout << j << " " ;
    //     }
    //     cout << "\n";
    // }


    int res = -1;

    for (auto a: mp) {
        // cout << a.first << "==> ";
        if (a.second.size() >= 2) {
            for (int i = 0; i < a.second.size() - 1; i++) {
                res = max(res, func(a.second[i], a.second[i + 1], n));
            }
        }
    }
    cout << res << "\n";
}   


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}