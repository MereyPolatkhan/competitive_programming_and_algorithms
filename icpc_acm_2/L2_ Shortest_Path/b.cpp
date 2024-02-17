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

int const N = 400;
int n;

int d[N][N];

void floyd_warshall() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void upd(int k1, int k2) {
    vector<int> ks;
    ks.pb(k1);
    ks.pb(k2);

    for (int k: ks)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    floyd_warshall();

    int q;
    cin >> q;
    while (q--) {
        int x, y, w;
        cin >> x >> y >> w;

        if (d[x][y] > w)
            d[x][y] = w, d[y][x] = w;

        upd(x, y);

        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // cout << i << "-" << j << " = " << d[i][j] << "\n";
                sum += d[i][j];
            }
        }
        cout << sum << " ";
    }


}


int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #else
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/
