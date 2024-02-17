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


int dist(int x, int y, int x1, int y1) {
    return abs(x - x1) + abs(y - y1);
}

int func(int n, int m, int i, int j) {
    return max(
        max(dist(1, 1, i, j), dist(1, m, i, j)), 
        max(dist(n, 1, i, j), dist(n, m, i, j))
    );
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> res;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res.pb(func(n, m, i, j));
        }
    }
    sort(all(res));

    for (int x: res) {
        cout << x << " ";
    }
    cout << "\n";

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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

