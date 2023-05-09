#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map <int, int> m;

    vector<int> a[n];

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            m[x]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int cur_size = a[i].size();
        for (auto j: a[i]) {
            if (m[j] >= 2) {
                cnt++;
            }
        }
        if (cnt == cur_size) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;

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