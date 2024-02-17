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


int get(int j, vector<int> &dp) {
    if (j == dp.size()) {
        return 0;
    }
    else if (j < dp.size()) {
        return dp[j];
    }
    else {
        return INT_MAX;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, INT_MAX);

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = min(dp[i + 1] + 1, get(i + a[i] + 1, dp));
    }
    cout << dp[0] << "\n";
}

void _solve() {
    int n;
    cin >> n;


    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<bool> can(n);
    for (int i = 0; i < n; i++) {
        if (a[i] <= n - 1 - i) {
            can[i] = true;
        }
        else {
            can[i] = false;
        }
    }

    vector<int> cst(n);
    int dest = n;
    for (int i = n - 1; i >= 0; i--) {
        if (can[i] == false) {
            cst[i] = dest - i;
        }
        else 
            dest = i;
    }


    ll res = n;
    for (int j = 0; j < n; j++) {
        ll cnt = j;
        int i = j;
        while (i < n) {
            if (can[i]) {
                i = i + a[i] + 1;
            }
            else {
                cnt += cst[i];
                i = i + cst[i];
            }
        }
        res = min(res, cnt);
    }


    cout << "res: " << res << "\n";
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) 
        cout << can[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) 
        cout << cst[i] << " ";
    cout << "\n";
    cout << "\n\n\n";
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

