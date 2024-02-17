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

ll calc(ll L, ll R) {
    return (R - L + 1) * (L + R) / 2;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll cnt_x = n / x;
    ll cnt_y = n / y;
    // cout << "cnt x : " << cnt_x << "   cnt y : " << cnt_y << "\n";
    ll minus = n / lcm(x, y);
        cnt_x -= minus, cnt_y -= minus;

    ll res = calc(n - cnt_x + 1, n)  -  calc(1, cnt_y);
    cout << res << "\n";
}

/*  things to check:
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

