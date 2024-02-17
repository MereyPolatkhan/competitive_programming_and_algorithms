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
int const N = 1e3 + 7;

void make_set(vector<int> &par) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int a, vector<int> &par) {
    if (a == par[a]) {
        return a;
    }
    return par[a];
}

void unite(int from, int to, vector<int> &par) {
    from = find(from, par);
    to = find(to, par);

    if (from == to)
        return;

    par[to] = from;    
}   

void solve() {
    vector<pair<int, pii>> g;

    cin >> n;
    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    cin >> m;

    vector<int> d(n + 1, -1);

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.pb({w, {a, b}});
        d[b] = a;
    }

    int check_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == -1) {
            check_cnt++;
        }
    }
    if (check_cnt != 1) {
        cout << -1 << "\n";
        return;
    }

    sort(all(g));

    vector<int> par(n + 1);
    make_set(par);

    vector<pii> mst;
    ll mst_sum = 0;

    for (auto &it: g) {
        int w = it.first;
        int from = it.second.first, to = it.second.second;

        if (find(to, par) == to) {
            mst.pb({from, to});
            mst_sum += w;
            unite(from, to, par);
        }
    }


    cout  << mst_sum << "\n";

}	


int main() { 
    #ifdef LOCAL
		freopen("input.txt", "r", stdin);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

