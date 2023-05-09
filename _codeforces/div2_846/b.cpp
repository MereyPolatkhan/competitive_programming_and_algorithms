#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    // vector<ll> s(n);

    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        p[i] = x;
        // s[i] = x;
    }

    for (ll i = 1; i < n; i++) p[i] += p[i - 1];
    
    // for (ll i = n - 2; i >= 0; i--) s[i] += s[i + 1];

    ll mx = -1e18;
    for (ll i = 0; i < n-1; i++) {
        mx = max(mx, gcd(p[n-1] - p[i], p[i]));
    }
    cout << mx << "\n";
}

int main() {

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}