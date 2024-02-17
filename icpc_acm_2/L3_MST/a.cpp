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
typedef pair<int, ll> pill;

int n, m;
int const N = 2e5 + 7;
 
void make_set(vector<int> &par, vector<int> &sz) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int a, vector<int> &par) {
    if (a == par[a]) {
        return a;
    }
    int pa = find(par[a], par);
    par[a] = pa;
    return pa;
}

void unite(int a, int b, vector<int> &par, vector<int> &sz) {
    a = find(a, par);
    b = find(b, par);
    if (a == b) {
        return;
    }

    if (sz[b] > sz[a]) {
        swap(a, b);
    }
    // merge 'B' to 'A'

    par[b] = a;
    sz[a] += sz[b];
}

void func() {
    vector<pair<ll, pii>> g;

    ll all = 0;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g.pb({z, {x, y}});
        all += z;
    }

    vector<int> par(N), sz(N);
    make_set(par, sz);

    vector<pii> mst;
    sort(all(g));    
    ll mst_sum = 0;
    for (int i = 0; i < m; i++) {
        ll w = g[i].first;
        pii e = g[i].second;

        if (find(e.first, par) != find(e.second, par)) {
            mst.pb(e);  
            mst_sum += w;
            unite(e.first, e.second, par, sz);
        }
    }
    cout << all - mst_sum << "\n";
}

void solve() {

    while (cin >> n >> m) {
        if (n and m) {
            func();
        }
        else {
            return;
        }
    }
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

