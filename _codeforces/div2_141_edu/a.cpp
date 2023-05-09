#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == sum) {
            swap(a[i], a[a.size() - 1]);
        }
        sum += a[i];
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == sum) {
            cout << "NO\n";
            return;
        }
        sum += a[i];
    } 
    cout << "YES\n";
    for (int i: a) cout << i << " ";
    cout << "\n";
}


int main() {
    // freopen("input.txt", "r", stdin);
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