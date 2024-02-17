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


bool check(ll a, ll l, ll r, ll m) {
    ll delta = r - l;
    delta = delta - ((m + delta) % a);
    ll b = l, c = l + delta;
    if (delta < 0) {
        b = r, c = r + delta;
    }

    if (l <= a and a <= r and l <= b and b <= r and l <= c and c <= r) {
        cout << a << " " << b << " " << c << "\n";
        return true;
    }
    return false;
}

void solve() {
    ll l, r, m;
    cin >> l >> r >> m;
    
    for (ll a = l; a <= r; a++) {
        if (check(a, l, r, m)) {
            return;
        }
    }
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
