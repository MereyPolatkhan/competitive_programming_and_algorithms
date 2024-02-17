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

int n;

bool check(ll x, vector<ll>& b) {
    vector<ll> a = b;
    for (int i = n - 1; i >= 2; i--) {
        if (a[i] < x) {
            return false;
        }
        ll d = min(b[i], a[i] - x) / 3;
        a[i] -= 3 * d;
        a[i - 1] += d;
        a[i - 2] += 2 * d;
    }

    return *min_element(all(a)) >= x;
}

void solve() {
    cin >> n;
    vector<ll> a;
    a.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    ll l = 0, r = 1e18;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid, a)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l << "\n";


    cout << "\n\n\n";
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
