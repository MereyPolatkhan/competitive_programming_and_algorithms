#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }

    long long sum = a[0];

    for (int i = 1; i < n; i++) {
        if (sum >= a[i]) {
            sum += a[i];
        }
        else {
            cout << "NO\n";
            return;
        }
    }  
    cout << "YES\n"; 
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