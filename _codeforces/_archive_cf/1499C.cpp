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



vector<ll> a, b;
int n;

ll func(int i, int j, ll min_a, ll min_b, ll sum_a, ll sum_b) {
    ll res = (ll)1e18;

    while (i < a.size() and j < b.size()) {
        min_a = min(min_a, a[i]);
        min_b = min(min_b, b[j]);
        sum_a += a[i];
        sum_b += b[j];

        res = min(res, 
            (sum_a + (n - (i + 1)) * min_a) + 
            (sum_b + (n - (j + 1)) * min_b)
        );

        i++, j++;
    }
    return res;
}



void solve() {
    cin >> n;
    a.clear(), b.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i % 2 == 0)
            a.pb(x);
        else 
            b.pb(x);
    }

    ll x = func(0, 0, a[0], b[0], 0, 0);
    ll z = func(1, 0, a[0], b[0], a[0], 0);

    // cout << "x: " << x << "\ty: " << y << "\tz: " << z << "\n";
    cout << min(x, z) << "\n";

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
