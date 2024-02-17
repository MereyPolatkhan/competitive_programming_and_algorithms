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

// const ull mod = (ull)1e9 + 7;
// const ull mod = 1000000000000000003;

const ull mod = 1e9 + 7;

const int N = 200;


vector<ull> fact(N), inv(N);

ull binpow (ull a, ull n) {
	ull res = 1;
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
    for (ull i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2) % mod;
    }
}

void solve() {
    precalc();

    ull n, k;
    cin >> n >> k;

    vector<ull> a(k + 1);

    for (int i = 0; i <= k; i++) {
        if (n - i < 0)
            continue;

        ull x = fact[n] * inv[i] % mod * inv[n - i] % mod;
        ull d = x / 2;
        if (x % 2) 
            d++;
    
        a[i] = d;
    }

    ull res = 0;
    for (int i = 0; i <= k; i++) {
        if (i + i == k) {
            res += 2 * a[i];
        }
        else {
            res += a[i];
        }
    }

    cout << res << "\n";
}


/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

