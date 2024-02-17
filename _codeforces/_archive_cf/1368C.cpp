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
    int n;
    cin >> n;

    vector<pii> res;
    for (int i = 0, j = 0; i <= n + 1, j <= n + 1; i++, j++)
        res.pb({i, j});
    for (int i = 1, j = 0; i <= n + 1, j <= n; i++, j++)
        res.pb({i, j});
    for (int i = 0, j = 1; i <= n, j <= n + 1; i++, j++)
        res.pb({i, j});

    cout << res.size() << "\n";
    for (pii x: res)
        cout << x.first << " " << x.second << "\n";

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
