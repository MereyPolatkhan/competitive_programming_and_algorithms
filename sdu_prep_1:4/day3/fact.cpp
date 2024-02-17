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
typedef pair<ll, ll> pii;
 
 
const ull mod = 1e9 + 7;
// const ull mod = (ll)999999999999999989;
ull N = (ll)2e6 + 7; 
 
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
    int x, y;
    cin >> x >> y;
    cout << fact[x] * inv[x - y]% mod * inv[y] % mod << "\n";
}   
 
 
 
/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
 
 
 
int main() {   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    precalc();
    solve();
    
    return 0;
}