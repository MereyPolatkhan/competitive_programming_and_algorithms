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

int n;

ll sum(int l, int r, vector<ll> &a) {
    return a[r] - a[l - 1];
}

ll func(int k, vector<ll> &a) {
    vector<ll> b;
    
    int l = 1;
    while (l <= n) {
        if (l + k - 1 <= n)
            b.pb(sum(l, l + k - 1, a));
        else 
            break;
        l += k;
    }
    // cout << "k: " << k << " ";
    // cout << "b: "; for (auto i: b) cout << i << " "; cout << "\n";

    return *max_element(all(b)) - *min_element(all(b));
}

void solve() {
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    // cout << "a: "; for (auto i: a) cout << i << " "; cout << "\n";


    ll res = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            res = max(res, func(i, a));
        }
    }
    cout << res << "\n";
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
    cin >> T;
    for (int test = 1; test <= T; test++) {
        #ifdef LOCAL
        // cout << "\n\n\ntest: #" << test << "\n";
        #endif
        solve();
    }

    return 0;
}

