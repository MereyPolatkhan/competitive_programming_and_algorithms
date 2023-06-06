#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll init = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'L') {
            init += i;
        }
        else {
            init += (n - 1 - i);
        }
    }
    
    vector<ll> a;

    for (ll i = 0; i < n; i++) {
        ll left = i;
        ll right = n - 1 - i;

        if (s[i] == 'L') {
            a.push_back(right - left);
        }
        else {
            a.push_back(left - right);
        }
    }
    
    sort(a.rbegin(), a.rend());

    if (a[0] < 0) {
        for (int i = 0; i < n; i++) cout << init << " "; cout << "\n";
        return;
    }

    for (ll i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    
    vector<ll> res;

    for (ll i = 0; i < n; i++) {
        if (res.size() > 0 and res.back() > init + a[i]) {
            res.push_back(res.back());
        }
        else {
            res.push_back(init + a[i]);   
        }
    }
    
    for (ll i : res) cout << i << " "; cout << "\n";
}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}