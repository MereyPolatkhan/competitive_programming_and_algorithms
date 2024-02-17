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


void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
    }
    
    int res = 1e9;

    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] - a[i - 1] <= s) {
                pos = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (pos >= 1 and a[pos] - a[i - 1] == s)
            res = min(res, i - 1 + n - pos);
    }


    if (res == 1e9) 
        cout << -1 << "\n";
    else 
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
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

