#include <bits/stdc++.h>

using namespace std;


void solve() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = a[0], mx = a[0];

    for (int & ai: a) {
        mn = min(mn, ai);
        mx = max(mx, ai);
    }

    if (mn == mx) {
        cout << 0 << "\n";
        return;
    }
    if (mn == 1) {
        cout << -1 << "\n";
        return;
    }

    vector< pair <int, int> > res;

    while (true) {
        int max_index = 0;
        int min_index = 0;
        for (int i = 0; i < n; i++) {
            if (a[max_index] < a[i]) {
                max_index = i;
            }
            if (a[min_index] > a[i]) {
                min_index = i;
            }
        }
        if (a[max_index] == a[min_index]){ 
            break;
        }

        res.push_back({max_index, min_index});
        a[max_index] = (a[max_index] + a[min_index] - 1) / a[min_index];
    }

    cout << res.size() << "\n";
    for (auto &i : res) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
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