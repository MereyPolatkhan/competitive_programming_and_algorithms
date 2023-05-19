#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> b;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b.push_back(a);
    }

    reverse(b.begin(), b.end());
    vector<int> res(m, -1);
    set<int> st;

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[i].size(); j++) {
            if (st.count(b[i][j]) == 0 and res[i] == -1) {
                res[i] = b[i][j];
            }
            st.insert(b[i][j]);
        }
    }

    reverse(res.begin(), res.end());
    for (int i : res) {
        if (i == -1) {
            cout << -1 << "\n";
            return;
        }
    }
    for (int i : res) cout << i << " ";
    cout << "\n";
}


int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}