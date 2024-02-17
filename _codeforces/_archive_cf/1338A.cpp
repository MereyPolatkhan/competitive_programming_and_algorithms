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

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}
 

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x: a)
        cin >> x;


    vector<ll> prefmax = a, suffmin = a;

    for (int i = 1; i < n; i++) {
        prefmax[i] = max(prefmax[i], prefmax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suffmin[i] = min(suffmin[i], suffmin[i + 1]);
    }

    ll d = 0;
    for (int i = 0; i < n; i++) {
        d = max(d, (prefmax[i] - suffmin[i]));
    }

    int p = 0;
    while (binpow(2, p) - 1 < d) 
        p++;

    cout << p << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
