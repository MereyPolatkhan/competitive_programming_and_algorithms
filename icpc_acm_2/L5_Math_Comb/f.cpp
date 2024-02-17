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

#include <climits>
#include <stack>
 
using namespace std;


int const N = 1e3;
int const MOD = 1e9 + 7;
long long fact[N + 5], inv[N + 5];

long long binpow_optimized (long long a, long long n) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res *= a;
        res %= MOD;
		a *= a;
        a %= MOD;
		n >>= 1;
	}
	return res;
}

void precalc() {
    fact[0] = 1;
    inv[0] = 1;

    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow_optimized(fact[i], MOD - 2) % MOD;
    }
}

void solve() {
    int k;
    cin >> k;
   
    int n = 0;

    map<int, int> mp;

    for (int i = 1; i <= k; i++) {
        int cnt;
        cin >> cnt;
        mp[i] = cnt;

        n += cnt;
    }

    
}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    precalc();

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

