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
    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int dp[n + 1][max_weight + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max_weight; j++) {
            dp[i][j] = 1e9;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= max_weight; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= a[i]) {
                dp[i][w] = min(dp[i][w], dp[i][w - a[i]] + 1);
            }
        }
    }


    if (dp[n][max_weight] == 1e9) 
        cout << -1 << "\n";
    else 
        cout << dp[n][max_weight] << "\n";
    // return;

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= max_weight; w++) {
            cout << dp[i][w] << " ";
        }
        cout << "\n";
    }


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

