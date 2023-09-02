#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
 
 
const ll mod = (ll)1e9 + 7;
ll N = (ll)2e6 + 7; 
 
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

vector<ll> fact(N), inv(N);
 
void precalc() {
    fact[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2) % mod;
    }
}
 
void solve() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << "\n";
        return;
    }

    n /= 2;

    string s;
    cin >> s;

    int a = 0;
    int b = 0;
    int cur = 0;
    for (char &c: s) {
        if (c == '(') {
            cur++;
            a++;
        }
        else {
            cur--;
            b++;
        }

        if (cur < 0){ 
            cout << 0 << "\n";
            return;
        }
    }
    
    if (a > n) {
        cout << 0 << "\n";
        return;
    }
    if (a == n) {
        cout << 1 << "\n";
        return;
    }

    
    int x = fact[2 * n - a - b] * inv[n - a] % mod * inv[n - b] % mod;
    int y = fact[2 * n - a - b] * inv[n - a - 1] % mod * inv[n - b + 1] % mod;

    cout << (x - y + mod) % mod << "\n";
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
