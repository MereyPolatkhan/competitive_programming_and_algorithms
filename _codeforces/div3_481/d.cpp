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

int func(int a0, int a1, vector<int> a, int cnt) {
    for (int i = 2; i < n; i++) {
        int need_to_be = a1 + (i - 1) * (a1 - a0);
        if (need_to_be == a[i]) {
            continue;
        }
        else if (abs(need_to_be - a[i]) <= 1) {
            cnt++;
        }
        else {
            return 1e9;
        }
    }
    return cnt;
}

void solve() {
    cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << 0 << "\n";
        return;
    }

    int mincnt = 1e9;

    for (int d1 = -1; d1 <= 1; d1++) {
        for (int d2 = -1; d2 <= 1; d2++) {
            mincnt = min(mincnt, func(a[0] + d1, a[1] + d2, a, abs(d1) + abs(d2)));
        }
    }
    if (mincnt == 1e9) {
        cout << -1 << "\n";
    }
    else {
        cout << mincnt << "\n";
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
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

