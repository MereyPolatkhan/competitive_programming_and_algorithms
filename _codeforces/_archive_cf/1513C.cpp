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


const ll mod = 1e9 + 7;
const int M = 2e5;
ll dp[M + 1234];

ll n, m;


void precalc() {
    for (int i = 0; i <= M; i++) {
        if (i <= 8)
            dp[i] = 2;
        else if (i == 9) 
            dp[i] = 3;
        else 
            dp[i] = dp[i - 10] + dp[i - 9];

        dp[i] %= mod;
    }
}


ll func(int d) {
    int k = 10 - d;
    if (m - k >= 0) {
        return dp[m - k];
    }
    return 1;
}

void solve() {
    cin >> n >> m;

    ll res = 0;
    while (n) {
        res += func(n % 10);
        res %= mod;
        n /= 10;
    }
    cout << res << "\n";
}

int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
