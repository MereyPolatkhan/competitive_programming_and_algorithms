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

void solve() {
    int n;
    cin >> n;

    map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;

        mp[b] += a;
    }    
        // for (auto it: mp) {
        //     cout << it.first << " " << it.second << "\n";
        // }        
        // cout << "\n\n\n";

    // int it = 19;
    ll res = 0, cnt = 0;
    while (mp.size()) {
        if (cnt >= mp.begin()->first) {
            // cout << "deal begin: " << mp.begin()->first << " " << mp.begin()->second << "\n";
            res += mp.begin()->second * 1;
            cnt += mp.begin()->second;
            mp.erase(mp.begin());
        }
        else {
            // cout << "deal rbegin(): " << mp.rbegin()->first << " " << mp.rbegin()->second << "\n";
            ll mn = min(mp.begin()->first - cnt, mp.rbegin()->second);
            if (mp.rbegin()->second - cnt > 0)  
                mn = min(mn, mp.rbegin()->second - cnt);
            // cout << "mn: " << mn << "\n";
            res += mn * 2;
            cnt += mn;
            mp.rbegin()->second -= mn;
            if (!mp.rbegin()->second)
                mp.erase(mp.rbegin()->first);
        }
        // cout << "cnt: " << cnt << "    res: " << res << "\n";
        // cout << "mp: \n";
        // for (auto it: mp) {
        //     cout << it.first << " " << it.second << "\n";
        // }        
        // cout << "\n\n\n";
    }
    cout << res << "\n";

    // cout << "\n\n\n";
    
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
