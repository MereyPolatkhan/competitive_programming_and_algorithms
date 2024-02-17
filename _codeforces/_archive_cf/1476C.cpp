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
#define int long long 



void solve() {
    int n;
    cin >> n;

    vector<int> c(n + 1), a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }


    int cur = c[2] + 2 + abs(a[2] - b[2]);
    int res = cur;

    for (int i = 3; i <= n; i++) {
        if (a[i] == b[i]) {
            cur = c[i] + 2;
        }
        else {
            cur = max(abs(a[i] - b[i]), cur - abs(a[i] - b[i])) + c[i] + 2;
        }
        res = max(res, cur);
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
        solve();
    }

    return 0;
}
