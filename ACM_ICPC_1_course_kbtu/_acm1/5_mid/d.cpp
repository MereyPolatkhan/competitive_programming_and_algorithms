#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll cases = 0;

void solve() {
    cases++;
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, ll> mp;
    for (ll i = 0; i < m; i++) {
        ll x; cin >> x;
        mp[x]++;
    }

    ll XOR = 0;
    ll bad = 0;
    for (ll i = 0; i < n; i++) {
        XOR = XOR ^ a[i];
        if (mp.count(XOR)) {
            bad++;
        }
    }

    ll good = n - bad;
    // if(mp.count(0)) good++;
    cout<< "Case " << cases << ": " << (good) % 100000007 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--){ 
        solve();
    }




    return 0;
}