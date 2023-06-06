#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;

    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    vector<int> a;
    
    for (int x: st) {
        a.push_back(x);
    }

    if (a.size() == 1) {
        cout << -1 << "\n";
        return;
    }


    vector<int> b;
    for (int i = 0; i < a.size() - 1; i++) {
        b.push_back(a[i + 1] - a[i]);
    }

    if (b.size() == 1) {
        cout << b[0] << "\n";
        return;
    }


    int res = b[0];
    for (int i = 1; i < b.size(); i++) {
        res = __gcd(res, b[i]);
    }
    cout << res << "\n";

}

int main() {
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