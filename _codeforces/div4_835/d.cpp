#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> a;
    int j = 0;
    
    for (int i = 1; i < n; i++) {
        if (b[i] != b[j]) {
            a.push_back(b[j]);
            j = i;
        }
    }
    a.push_back(b[j]);

    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if ((i == 0 || a[i - 1] > a[i]) && (i == a.size() - 1 || a[i] < a[i + 1])) {
            cnt++;
        }
    }

    if (cnt == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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