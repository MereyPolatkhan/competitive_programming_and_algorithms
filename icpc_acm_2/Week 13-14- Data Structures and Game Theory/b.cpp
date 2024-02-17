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
typedef pair<int, int> pii;
typedef unsigned short int usi;



struct SegTree {
    int sz = 1;
    vector<int> tree;
 
    void init(int n) {
        while (sz < n) {
            sz *= 2;
        }
        tree.assign(2 * sz, INT_MAX);
    }
 
    void built(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx - 1) {
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
        }
        else {
            int m = (lx + rx) / 2;
            built(a, 2 * x + 1, lx, m);
            built(a, 2 * x + 2, m, rx);
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }
 
    void built(vector<int> &a) {
        init(a.size());
 
        built(a, 0, 0, sz);
    }
 
 
    void set(int i, int val, int x, int lx, int rx) {
        if (lx == rx - 1) {
            tree[x] = val;
        }
        else {
            int m = (lx + rx) / 2;
            if (i < m) {
                set(i, val, 2 * x + 1, lx, m);
            }
            else {
                set(i, val, 2 * x + 2, m, rx);
            }
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }
 
    void set(int i, int val) {
        set(i, val, 0, 0, sz);
    }
 
 
 
    int getMin(int l, int r, int x, int lx, int rx) {
        if (l >= rx or lx >= r) {
            return INT_MAX;
        }
        else if (l <= lx and rx <= r) {
            return tree[x];
        }
        else {
            int m = (lx + rx) / 2;
            return min(
                getMin(l, r, 2 * x + 1, lx, m),
                getMin(l, r, 2 * x + 2, m, rx)
            );
        }
    }
    
    int getMin(int l, int r) {
        return getMin(l, r, 0, 0, sz);
    }
};
 


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n), suffix(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] - (i + 1);
        suffix[i] = a[i] - (n - i);
    }
    
    SegTree s1, s2;
    s1.built(pref), s2.built(suffix);

    ll type, pos, val;
    while (q--) {
        cin >> type;
        cin >> pos;
        pos--;
        if (type == 1) {
            cin >> val;
            pref[pos] += (val - a[pos]);
            suffix[pos] += (val - a[pos]);
            a[pos] = val;

            s1.set(pos, pref[pos]);
            s2.set(pos, suffix[pos]);
        }
        else if (type == 2) {
            ll r1 = s1.getMin(0, pos) - pref[pos];
            ll r2 = s2.getMin(pos, n - 1) - suffix[pos];
            cout << 1LL * a[pos] + 1LL * min(r1, r2) << "\n";
        }
    }
}



int main() { 
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

