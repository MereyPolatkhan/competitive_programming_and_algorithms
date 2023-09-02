#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;



ll calc(ll x) {
    return (x * (x - 1) / 2);
}

void solve() {

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];    
    
    for (int i = 0; i < n; i++) {
        a[i] -= i;
    }

    unordered_map<ll, ll> mp;
    for (ll &x: a) {
        mp[x]++;
    }

    ll res = 0;
    for (auto &x: mp) {
        res += calc(x.second);
    }

    cout << res << "\n";

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

