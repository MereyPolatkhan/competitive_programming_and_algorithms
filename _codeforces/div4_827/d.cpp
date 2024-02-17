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



void solve() {
    int n;
    cin >> n;


    vector<ll> a(1000 + 1, 0);
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[x] = max(i, a[x]);
    }
    ll res = -1;
    for (int i = 1; i <= 1000; i++) {
        if (a[i]) {
            for (int j = i; j <= 1000; j++) {
                if (a[j]) {
                    if (gcd(i, j) == 1) {
                        res = max(res, (ll) a[i] + a[j]);
                    }
                }
            }
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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

