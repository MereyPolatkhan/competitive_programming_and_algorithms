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
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];


    vector<int> d(n + 2, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }

    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + d[i];
        // cout << b[i] << " ";
    }

    sort(all(a)), sort(all(b));
    ll res = 0;
    for (int i = 1; i <= n; i++) 
        res += 1LL * a[i] * b[i];
    cout << res << "\n";
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
