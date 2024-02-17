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

ll func(vector<int> &a) {
    ll cur = 0, res = 0;
    for (int &x: a) {
        cur += x;
        res = max(res, cur);
        cur = max(cur, 0LL);
    }
    // res = max(res, cur);
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i += 2) {
        res += a[i];
    }

    vector<int> b, c;
    for (int i = 0; i + 1 < n; i += 2) {
        b.pb(a[i + 1] - a[i]);
    }

    for (int i = 1; i + 1 < n; i += 2) {
        c.pb(a[i] - a[i + 1]);
    }

    // cout << "b: "; for (int x: b) cout << x << " "; cout << "\n";
    // cout << "c: "; for (int x: c) cout << x << " "; cout << "\n";
    // cout << "\n\n";

    cout << res + max(func(b), func(c)) << "\n";
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
