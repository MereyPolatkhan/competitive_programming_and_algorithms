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



int const MOD = 998244353;
int const N = 5000;


void solve() {
    int q, sum;
    cin >> q >> sum;

    vector<ull> dp(N + 7, 0);
    dp[0] = 1;

    while (q--) {
        char c; ull coin;
        cin >> c >> coin;

        if (c == '+') {
            for (int i = sum; i >= coin; i--) {
                dp[i] += dp[i - coin];
                dp[i] %= MOD;
            }
        }

        if (c == '-') {
            for (ull i = coin; i <= sum; i++) {
                    // dp[i] -= dp[i - coin];
                    dp[i] += (MOD - dp[i - coin]);
                    dp[i] %= MOD;
            }
        }
        
        cout << dp[sum] % MOD << "\n";

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

