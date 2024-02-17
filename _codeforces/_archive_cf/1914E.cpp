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


bool cmp(pii a, pii b) {
    return a.first + a.second > b.first + b.second;
}

void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for (pii &x: a) 
        cin >> x.first;

    for (pii &x: a) {
        cin >> x.second;
    }

    sort(all(a), cmp);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            res += a[i].first - 1;
        else 
            res -= a[i].second - 1;
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
