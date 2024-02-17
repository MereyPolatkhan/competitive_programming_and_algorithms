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
#define L first
#define R second

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef pair<ll, ll> pii;

bool check(ll k, vector<pii> &a) {
    ll left = 0, right = 0;

    for (auto &[aL, aR]: a) {
        // calculations
        
        left = max(left - k, aL);
        right = min(right + k, aR);

        // checking
        if (right < left) 
            return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].L >> a[i].R;
    }

    ll l = -1, r = 1e18;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid, a))
            r = mid;
        else    
            l = mid;
    }
    cout << r << "\n";
}


int main() { 
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

