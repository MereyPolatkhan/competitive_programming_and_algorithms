#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll binpow (ll a, ll n, ll mod) {
	ll res = 1;
	while (n)
		if (n & 1) {
			res = res * a % mod; 
			--n;
		}
		else {
			a = a * a % mod;
			n >>= 1;
		}
	return res % mod;
}

const ll N = (ll)1e5;
const ll MOD = (ll)1e9 + 7; 
vector<ll> fact(N), invfact(N);

void precalc() {
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = binpow(fact[i], MOD - 2, MOD);
    }
}

    

void solve() {
    ll n, m;
    cin >> n >> m;

    cout << (fact[n + m] % MOD * invfact[n] % MOD) % MOD * invfact[m] % MOD << "\n";
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

    precalc();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

