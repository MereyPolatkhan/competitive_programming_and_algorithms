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
    ll n, k, s;
    cin >> n >> k >> s;

    if (k > s or (n - 1) * k < s) {  
        cout << "NO\n";
        return;
    }

    vector<ll> res;
    ll c = 1;
    while (s and k and k - 1 <= s - (n - 1)) {
        c = n - c + 1;
        res.pb(c);
        k--;
        s -= (n - 1);
    }




    ll delta = s - k + 1;
    if (delta >= 2) {
        if (c == 1) {
            c += delta;
            res.pb(c);
            s -= delta;
            k--;
        }
        else if (c == n) {
            c -= delta;
            res.pb(c);
            s -= delta;
            k--;
        }   
        else {
            cout << "NO\n";
            return;
        }
    }




    ll m = k;

    while (m) {
        while (m and c < n) {
            m--;
            c++;
            res.pb(c);
        }


        while (m and c > 1) {
            m--;
            c--;
            res.pb(c);
        }
    }


    cout << "YES\n";


    for (auto it: res) 
        cout << it << " ";
    cout << "\n";
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
