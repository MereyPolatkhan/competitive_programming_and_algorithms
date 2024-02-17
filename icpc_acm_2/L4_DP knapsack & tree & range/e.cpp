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

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int n;
int const N = (int)1e5 + 7;
int const MOD = (int)1e9 + 7;
vector<int> g[N];
long long dp[2][N];

void dfs(int v, int par) {
    dp[0][v] = 1;
    dp[1][v] = 1;

    for (int to: g[v]) {
        if (to != par) {
            dfs(to, v);
            dp[0][v] *= (dp[0][to] + dp[1][to]) % MOD;
            dp[0][v] %= MOD;

            dp[1][v] *= (dp[0][to]) % MOD;
            dp[1][v] %= MOD;
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;

        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, -1);

    cout << (dp[0][1] + dp[1][1]) % MOD << "\n";

}


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

