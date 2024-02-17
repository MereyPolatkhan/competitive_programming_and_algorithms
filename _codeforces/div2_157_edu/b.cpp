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


void solve() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    sort(all(a));

    vector<int> x, y;
    
    for (int i = 0; i < n; i++) {
        x.pb(a[i]);
    }
    for (int i = n; i < 2 * n; i++) {
        y.pb(a[i]);
    }

    vector<pii> res;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        res.pb({x[i], y[i]});
        if (i) {
            s += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        }
    }

    cout << s << "\n";
    for (pii it: res) {
        cout << it.first << " " << it.second << "\n";
    }

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

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

