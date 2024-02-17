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


int const mod = 1e9 + 7, N = 2e5;
ll fact[N + 7], inv[N + 7];

ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1LL;
    }
    else if (n % 2) {
        return (binpow(a, n - 1) * a) % mod;
    }
    else {
        ll p = binpow(a, n / 2);
        return p * p % mod;
    }
}

void precalc() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = binpow(fact[i], mod - 2) % mod;
    }
}

ll C(ll n, ll k) {
    if (n < k) 
        return 0;

    // return fact[n] * inv[n - k] % mod * inv[k] % mod;
    return n * (n - 1) / 2;
}


void solve() {
    int n, cnt = 3, delta = 2;
    cin >> n;
    // cin >> cnt >> delta;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    sort(rall(a));
    // for (int x: a) cout << x << " "; cout << "\n";
    ll res = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r + 1 < n and a[l] - a[r + 1] <= delta) {
            r++;
        }   

        res += C(r - l, cnt - 1);
        // cout << l << " " << r << "\n";
        // res %= mod;
    }

    cout << res << "\n";
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
