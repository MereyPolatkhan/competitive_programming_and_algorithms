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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 10, vector<int> (m + 10, 1e9));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 10, vector<int> (m + 10, 1e9));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1)  
                continue;
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }

    dp[n][m] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n and j == m)
                continue;
            
            dp[i][j] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1]) + 1);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // return;
    

    map<int, map<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mp[dp[i][j]][a[i][j]]++;
        }
    }

    if ((n + m) % 2 == 0)
        mp.erase(mp.rbegin()->first);

    int res = 0;
    for (auto it: mp) {
        res += min(it.second[0], it.second[1]);
    }
    cout << res << "\n\n\n";
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
