#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;



ll n;
ll m;

void fill(vector<ll> &a, ll x, ll cnt) {
    while (cnt > 0) {
        ll i = n - 1;
        while (i >= 0 and cnt > 0) {
            if (a[i] == (1e9+7)) 
                cnt--;
            i--;
        }
        for (ll j = max(i,(ll) 0); j < n; j++) {
            if (a[j] == (1e9+7)) {
                a[j] = x;
                break;
            }
        }
    }

}

void solve() {
    cin >> n;

    m = n * (n - 1) / 2;

    vector<ll> b(m);
    map<ll, ll> mp;
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }

    vector<ll> a(n, (1e9+7));

    for (auto &it: mp) {
        fill(a, it.first, it.second);
    }
    ll mx = *max_element(all(b));

    for (ll i = 0; i < n; i++) {
        if (a[i] == (1e9+7)) {
            a[i] = mx;
        }
    }
    
    for (ll &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}












/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

