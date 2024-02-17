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
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


double dp[2100][2100];
int n, t;
double p;

void solve() {
    cin >> n >> p >> t;
    dp[0][0] = 1.0;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i + 1][j + 1] += dp[i][j] * p;
            if (j == n) {
                dp[i + 1][j] += dp[i][j];
            }   
            else {
                dp[i + 1][j] += dp[i][j] * (double)(1.0 - p);
            }
        }
    }
    double res = 0;
    for (int j = 1; j <= n; j++) {
        res += 1.0 * j * dp[t][j];
    }
    cout << fixed << setprecision(10) << res << "\n";
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
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}

