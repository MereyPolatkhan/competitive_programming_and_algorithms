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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

ll x, y;
ll sum = 0;
ll func(ll val) {
    return max(0LL, x - val) + max(0LL, y - (sum - val));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(all(a));

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        int index = lower_bound(all(a), x) - a.begin();
        if (index == n) 
            index--;
    
        ll val1 = func(a[index]), val2 = func(a[max(0, index - 1)]);
        cout << min(val1, val2) << "\n";
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
