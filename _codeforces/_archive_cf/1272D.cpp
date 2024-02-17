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


int len(pii el) {
    return el.second - el.first + 1;
}
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pii> b;

    for (int l = 0, r = 0; r < n; r++) {
        bool used = false;
        while (r + 1 < n and a[r] < a[r + 1]) {
            r++;
        }
        b.pb({l, r});
        l = r + 1;
    }

    int res = b.back().second - b.back().first + 1;
    for (int i = 0; i < b.size() - 1; i++) {
        res = max(res, b[i].second - b[i].first + 1);
        if (len(b[i]) >= 2 and a[b[i].second - 1] < a[b[i + 1].first]) {
            res = max(res, len(b[i + 1]) + len(b[i]) - 1);
        }
        if (len(b[i + 1]) >= 2 and a[b[i].second] < a[b[i + 1].first + 1]) {
            res = max(res, len(b[i + 1]) + len(b[i]) - 1);
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
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
