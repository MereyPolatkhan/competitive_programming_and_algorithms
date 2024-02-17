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

#define int long long 


void solve() {
    int x, n;
    cin >> x >> n;

    vector<int> ds;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ds.pb(i);
            if (i * i != x) {
                ds.pb(x / i);
            }
        }
    }


    int res = 1;
    for (int d: ds) {   
        int rem = (x - (n - 1) * d);
        if (rem > 0 and rem % d == 0) {
            res = max(res, d);
        }
    }

    cout << '\n' << res << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
