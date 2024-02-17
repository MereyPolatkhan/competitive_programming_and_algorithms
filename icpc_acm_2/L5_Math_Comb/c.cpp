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


int const N = 1e6;
int const MOD = 1e9 + 7;


long long binpow(long long a, long long n) {
    if (n == 0) {
        return 1LL * 1;
    }
    else if (n % 2 == 0) {
        long long b = binpow(a, n / 2);
        return b * b % MOD;
    }
    else {
        return binpow(a, n - 1) * a % MOD;
    }
}

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


long long fact[N], inv[N];

void precalc() {
    fact[0] = 1;
    inv[0] = 1;

    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD - 2) % MOD;
    }
}

void solve() {
    long long a, b;
    cin >> a >> b;

    cout << fact[a] * inv[b] % MOD * inv[a - b] % MOD << "\n";
}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    precalc();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

