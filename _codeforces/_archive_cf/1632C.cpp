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


int const N = 20;
vector<int> dtob(int x) {
    vector<int> res;
    while (x) {
        res.pb(x % 2);
        x /= 2;
    }
    while (res.size() < N)
        res.pb(0);

    // reverse(all(res));
    return res;
}



void solve() {
    int a, b;
    cin >> a >> b;

    int res = min(b - a, (a | b) - b + 1);

    int const m = res;
    int y = b;
    for (int i = 1; i <= m; i++) {
        y++;
        if ((a | y) == y) {
            res = min(res, i + 1);
            break;
        }
    }
    for (int i = 1; i <= m; i++) {
        a++;
        if ((a | b) == b) {
            res = min(res, i + 1);
            break;
        }
    }
    cout << res << "\n";
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
        if (test == 42) {
            // int x, y;
            // cin >> x >> y;
            // cout << x << "_" << y << ";\n";
        }
        solve();
    }

    return 0;
}
