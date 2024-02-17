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
typedef unsigned long long ull;
typedef pair<ll, ll> pii;


void solve() {

    ll n, m;
    cin >> n >> m;

    if (n == m) {
        cout << n << "\n";
        return;
    }

    map<ll, vector<ll>> mp;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x].pb(i);
    }

    ll l = 1e9;
    ll r = -1e9;
    ll i = mp.begin()->first;

    for (auto &it: mp) {
        if (it.second.size() <= m) {
            l = min(l, it.second[0]);
            r = max(r, it.second.back());
            m -= it.second.size();
        }
        else {
            i = it.first;
            break;
        }
    }
    if (m == 0) {
        cout << r - l + 1 << "\n";
        return;
    }

    // for (auto it: mp) {
    //     cout << it.first << ": ";
    //     for (ll i: it.second) {
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }

    vector<ll> a = mp[i];

    if (l == 1e9) {
        l = 0;
        r = m - 1;

        ll res = 1e9;

        while (r < a.size()) {
            res = min(res, a[r] - a[l] + 1);
            r++;
            l++;
        }
        cout << res << "\n";
        return;
    }


    ll cnt = 0;
    vector<pii> dest; 

    for (ll index: a) {
        if (index < l) {
            dest.pb({l - index, 0});
        }
        else if (l <= index and index <= r) {
            cnt++;
        }
        else {
            dest.pb({index - r, 1});
        }
    }
    // cout << "cnt: " << cnt << "m: " << m << "\n";
    if (m <= cnt) {
        cout << r - l + 1 << "\n";
        return;
    }
    else {
        m -= cnt;
    }
    // cout << "m: " << m << "\n";

    sort(all(dest));

    for (auto it : dest) {
        if (m == 0) {
            break;
        }
        if (it.second == 0) { // L
            l -= it.first;
        }   
        else if (it.second == 1) { // R
            r += it.first;
        }
        m--;
    }

    cout << r - l + 1 << "\n";
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

    solve();


    return 0;
}

