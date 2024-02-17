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



void solve() {

    int n, sum;
    cin >> n >> sum;

    int const MOD = 1e9 + 7;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> dp(sum + 1);
    dp[0] = 1;

    for (int coin: a) {
        for (int x = 1; x <= sum; x++) {
            if (x - coin >= 0) {
                dp[x] += dp[x - coin];
                dp[x] %= MOD;
            }
        }
       
        /*
        cout << "after coin: #" << coin << ":\n";

        for (int i = 0; i <= sum; i++) 
            cout << dp[i] << " ";
        cout << "\n";

        for (int i = 0; i <= sum; i++) 
            cout << i << " ";
        
        cout << "\n\n\n";
        */

    }
    
    cout << dp[sum] << "\n";
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

