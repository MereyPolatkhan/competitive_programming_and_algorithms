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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    map<ll, vector<ll>> mp;
    for (int x: a) {
        if (x % k)
            mp[x % k].pb(x);
    }

    for (auto &it: mp) {
        for (ll &x: it.second) {
            ll c = (x / k) + (x % k > 0);
            x = c * k - x;
        }
    }

    if (mp.size() == 0) {
        cout << 0 << "\n";
        return;
    }

    ll res = 0;
    for (auto &it: mp) {
        ll c = 0;
        for (ll &j : it.second) {
            j += (k * c++);
            res = max(res, j);
        }
    }
    cout << res + 1 << "\n";
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
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}



/*
x 
k
a[i], delta;

(x + a[i]) % k == 0
(x % k == 0) + (a[i] % k == 0) 



*/