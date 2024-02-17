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


const int mod = 1000000007;
ll const N = 1e3;
ll fact[N + 7], inv[N + 7];


ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;

        n >>= 1;
    }
    return res;

}


ll C(ll n, ll k) {
    if (n - k < 0) 
        return 0;
    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    ll n, x, pos;
    cin >> n >> x >> pos;   

    int l = 0, r = n;
    int less = x - 1, big = n - x;
    // cout << "init: less: " << less << "  big: " << big << "\n";
    ll res = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == pos)
            l = mid + 1;
        else if (mid < pos) {
            res = (res * less--) % mod;
            l = mid + 1;
        }
        else {
            res = (res * big--) % mod;
            r = mid;
        }
        // cout << "less: " << less << "  big: " << big << "\n";
    }

    res = (res * fact[less + big]) % mod;
    cout << res << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = binpow(fact[i], mod - 2);
    }


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
