#include <bits/stdc++.h>


using namespace std;


void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    int p = 0;

    for (int i = 1; i < n; i++) {
        if (a[i].second == a[i - 1].second + 1) {
            continue;
        }
        p++;
    }


    if (p + 1 <= k) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }    

    
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}