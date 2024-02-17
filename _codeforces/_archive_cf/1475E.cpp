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

struct cmp {
    bool operator()(const  int& a, const  int& b) const {
        return a > b;
    }
};


 
const ll mod = (ll)1e9 + 7;
ll N = (ll)2e3; 
 
vector<ll> fact(N + 1), inv(N + 1);
 
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
ll C(int n, int k) {    
    return fact[n] * inv[n - k] % mod * inv[k] % mod;
}


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x: a) 
        cin >> x;

    map<int, int, cmp> mp;
    for (int x: a) 
        mp[x]++;

    for (auto it: mp) {
        // cout << it.first << "  " << it.second << "\n";
        if (k >= it.second) 
            k -= it.second;
        else {
            cout << C(it.second, k) << "\n";
            return;
        }
    }
    cout << 1 << "\n";
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
