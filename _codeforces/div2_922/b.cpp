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

typedef pair<int, int> pii;


int n;
void solve() {
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];


    vector<pii> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = {a[i], i};
    }

    sort(all(p));

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        res.pb(b[p[i].second]);
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i].first << " ";
    }
    cout << "\n";
    for (int x: res) {
        cout << x << " ";
    }
    cout << "\n\n";
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
