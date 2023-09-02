#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
 
 
const ll mod = (ll)1e9 + 7;
ll N = (ll)1e6 + 7; 
 
vector<ll> fact(N), inv(N);
 
ll binpow (ll a, ll n) {
	ll res = 1;
	while (n)
		if (n & 1) {
			res = (res * a) % mod;
			--n;
		}
		else {
			a = (a * a) % mod;
			n >>= 1;
		}
	return res;
}
 
 
 
void precalc() {
    fact[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2) % mod;
    }
}
 
void solve() {
    string s;
    cin >> s;
    ll n = s.size();
 
    // for (ll i = 0; i <= n; i++) {
    //     cout << "i : " << i << "  fact[i]: " << fact[i] << " inv[i]: " << inv[i] << "\n";
    // }
 
    map<char, ll> mp;
    for (ll i = 0; i < n; i++) {
        mp[s[i]]++;
    }
 
    ll ans = fact[n];
 
    for (auto it: mp) {
        ans = ans * inv[it.second] % mod;
    }
    cout << ans << "\n";
}   
 
 
 
/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
 
 
 
int main() {   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    precalc();
 
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
