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


int const N = 1e5 + 5;
vector<int> g[N];
bool cat[N], used[N];

int n, m;
int res = 0;

void dfs(int v, int cnt) {
    used[v] = true;
    if (cnt > m) {
        return;
    }
    for (int y: g[v]) {
        if (!used[y]) {
            if (cat[y]) {
                dfs(y, cnt + 1);
            }
            else {
                dfs(y, 0);
            }
        }
    }

    if (cnt <= m and g[v].size() == 1 and v != 1) {
        // cout << "v: " << v << " cnt: " << cnt << "\n";
        res++;
    }
}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, cat[1]);

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
