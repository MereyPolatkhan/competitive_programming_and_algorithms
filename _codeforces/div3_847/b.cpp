#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s, r;
    cin >> n >> s >> r;

    int mx = s - r;
    s = r;
    n = n - 1;
    vector<int> a(n, 0);

    int i = 0;
    int cur = 1;
    while (s > 0) {
        if (i >= n) {
            i = 0;
            cur++;
        }
        s = s + a[i];
        a[i] = cur;
        s = s - cur;

        i++;
    }
    a.push_back(mx);
    for (auto i: a) cout << i << " "; cout << "\n";
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