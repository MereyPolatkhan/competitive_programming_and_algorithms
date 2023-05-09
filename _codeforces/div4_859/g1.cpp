#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        in[i] = a[i];
    }

    sort(a.begin(), a.end());

    ll sum = 0;
    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }

    
    for (int i = 1; i < n; i++) {
        
    }

    cout << "YES\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }





    return 0;
}