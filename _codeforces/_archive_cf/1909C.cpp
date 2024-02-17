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

vector<int> func(vector<int> &l, vector<int> &r) {
    vector<int> a;
    multiset<int> st(all(r));

    sort(rall(l));

    for (int x: l) {
        int y = *st.upper_bound(x);
        st.erase(st.find(y));

        a.pb(y - x);
    }

    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> a = func(l, r);
    sort(all(a));
    sort(rall(c));

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += 1LL * a[i] * c[i];
    }
    cout << res << "\n";
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
