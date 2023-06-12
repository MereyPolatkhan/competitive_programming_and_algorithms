#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;

ll func(ll n, ll k) {
    ll res = 0;
    for (int i = k; i <= n; i++) {
        res += (n - i + 1);
    }
    return res;
}

void solve() {
    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ranges;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= q) {
            cnt++;
        }
        else {
            ranges.pb(cnt);
            cnt = 0;
        }
    }
    ranges.pb(cnt);
    ll res = 0;
    for (ll &x: ranges) {
        if (x >= k) res += func(x, k);
    }
    cout << res << "\n";
}   

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
