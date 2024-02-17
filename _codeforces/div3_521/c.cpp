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

    vector<ll> a(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    map<ll, ll> x;
    for (int i = 0; i < n; i++) {
        x[i] = sum - a[i]; 
    }

    map<ll, set<ll>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].insert(i);
    }



    vector<ll> res;
    for (auto &it: x) {
        ll i = it.first;
        ll sumx = it.second;
        if (sumx % 2) 
            continue;
        
        ll y = sumx / 2;

        if (mp.count(y)) {
            if ((mp[y].count(i) and mp[y].size() >= 2) or !mp[y].count(i)) {
                res.pb(i);
            }
        }
    }

    cout << res.size() << "\n";
    for (ll i : res) {
        cout << i + 1 << " ";
    }
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

