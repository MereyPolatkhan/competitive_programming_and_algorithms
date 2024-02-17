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


ll const mod = 1e9 + 7;

ll binpow(ll a, ll n) {
    if (n == 1) {
        return a;
    }
    else if (n % 2) {
        return binpow(a, n - 1) * a % mod;
    }
    else {
        ll p = binpow(a, n / 2);
        return p * p % mod;
    }
}

void solve() {
    int n;
    cin >> n;

    ll f = 1;
    for (int i = 1; i <= n; i++)
        f *= i, f %= mod;
    cout << (f + mod - binpow(2, n - 1)) % mod << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
