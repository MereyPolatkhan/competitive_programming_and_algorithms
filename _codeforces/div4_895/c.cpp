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

#define FILE

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

ll l, r;

bool even() {
    int a = l - 2, b = r - 2;

    for (int i = a; i <= b; i++) {
        if (i >= 1 and i % 2 == 0) {
            cout << i << " " << 2 << "\n";
            return true;
        }
    }
    return false;
}

vector<ll> divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0) {
            if (n / i == i){
                // cout <<" "<< i;
                res.pb(i);
            }
            else {
                // cout << " "<< i << " " << n/i;
                res.pb(i);
                res.pb(n / i);
            } 
        }
    }
    sort(all(res));
    return res;
}

bool odd() {
    vector<ll> a = divisors(l);
    for (ll x: a) {
        if (x >= 3 and l - x >= 3 and gcd(x, l - x) != 1) {
            cout << x << " " << l - x << "\n";
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> l >> r;
    if (even()) 
        return;
    
    if (odd())
        return;
    cout << -1 << "\n";
}

/*  things to check:
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

