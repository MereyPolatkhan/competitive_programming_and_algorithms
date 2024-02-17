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
    int n, k;
    cin >> n >> k;

    vector<set<int>> g(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }

    map<int, set<int>> mp;
    for (int i = 1; i <= n; i++) {
        mp[g[i].size()].insert(i);
    }

    for (int i = 1; i <= k; i++) {
        if (mp.size() == 1) {
            mp.erase(mp.begin());
            break;
        }
        set<int> st = mp.begin()->second;
        mp.erase(mp.begin());
        for (int v: st) {
            int y = *g[v].begin(); g[v].clear();
            if (mp[g[y].size()].size() == 1) {
                mp.erase(g[y].size());
            }
            else {
                mp[g[y].size()].erase(y);
            }
            g[y].erase(v);
            mp[g[y].size()].insert(y);
        }

    }

    int res = 0;
    for (auto it: mp) {
        res += it.second.size();
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
