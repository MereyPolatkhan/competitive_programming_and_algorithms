
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


int const mod = 998244353, N = 2e5;

ll fact[N + 7], inv[N + 7];

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
    for (int i = 1; i <= N + 1; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = binpow(fact[i], mod - 2) % mod;
    }
}


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(all(a));
    if (count(all(a), mx) >= 2) {
        cout << fact[n] << "\n";
        return;
    }
    
    int cnt = count(all(a), mx - 1);

    ll all = fact[n];
    ll bad = fact[n] * fact[cnt] % mod * inv[cnt + 1] % mod;

    cout << (all - bad + mod) % mod << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
