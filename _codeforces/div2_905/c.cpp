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

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;

vector<ll> primeFactors(ll n) {  
    vector<ll> res;
    while (n % 2 == 0) {  
        res.pb(2);  
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2) {  
        while (n % i == 0) {  
            res.pb(i);  
            n = n/i;  
        }  
    }  
    if (n > 2)  
        res.pb(n); 


    return res;
}  


void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> b = a;


    vector<ll> facts = primeFactors(k);
    
    ll res = 0;

    for (ll p: facts) {
        ll min_index = 0;
        ll min_val = 2e9;

        for (ll i = 0; i < n; i++) {
                ll raz = a[i] / p;
                if (a[i] % p) 
                    raz++;
                
                ll delta = ((raz) * p - a[i]);

                if (min_val > delta) {
                    min_index = i;
                    min_val = delta;
                }
            
        }
        a[min_index] += min_val;
        a[min_index] /= p;
        res += min_val;
    }
    

    if (k != 4) {
        cout << res << "\n";
        return;
    }

    facts.clear();
    facts.pb(k);
    ll res2 = 0;
    a.clear();
    a = b;
    for (ll p: facts) {
        ll min_index = 0;
        ll min_val = 2e9;

        for (ll i = 0; i < n; i++) {
                ll raz = a[i] / p;
                if (a[i] % p) 
                    raz++;
                
                ll delta = ((raz) * p - a[i]);

                if (min_val > delta) {
                    min_index = i;
                    min_val = delta;
                }
            
        }
        a[min_index] += min_val;
        a[min_index] /= p;
        res2 += min_val;
    }

    cout << min(res, res2) << "\n";
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
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

