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

int const MOD = 1e9 + 7;
int const N = 20;
int n, m;

ll dp[1 << N][N];
vector<int> g[N];


void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[b].pb(a);
    }

    dp[1][0] = 1;

    for (int s = 2; s < 1 << n; s++) {
        if ((s & (1 << 0)) == 0) {
            continue;
        }

        if ((s & (1 << (n - 1))) and s != ((1 << n) - 1)) {
            continue;
        }

        for (int end = 0; end < n; end++) {
            if ((s & (1 << end)) == 0) 
                continue;

            int prev = s - (1 << end);
            for (int j : g[end]) {
                if ((s & (1 << j))) {
                    dp[s][end] += dp[prev][j];
                    dp[s][end] %= MOD;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << "\n";
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

